#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>
#include <sys/types.h>

// macros for error handling
#include "common.h"

#define N 100   // child process count
#define M 10    // thread per child process count
#define T 3     // time to sleep for main process

#define FILENAME	"accesses.log"

/*
 * data structure required by threads
 */
typedef struct thread_args_s {
    unsigned int child_id;
    unsigned int thread_id;
} thread_args_t;

/*
 * parameters can be set also via command-line arguments
 */
int n = N, m = M, t = T;

/* TODO: declare as many semaphores as needed to implement
 * the intended semantics, and choose unique identifiers for
 * them (e.g., "/mysem_critical_section") */
#define SEM_NAME "/mysem_critical_section" // per sincronizzare gli N processi figlio
sem_t   *process_sem;
sem_t   sem; // per sincronizzare gli M thread in ogni processo figlio

/* TODO: declare a shared memory and the data type to be placed 
 * in the shared memory, and choose a unique identifier for
 * the memory (e.g., "/myshm") 
 * Declare any global variable (file descriptor, memory 
 * pointers, etc.) needed for its management
 */
#define SHM_NAME "/myshm"
#define SIZE 999 //??????
int fd_shm; // per shmem
int *pt; // per mapping


/*
 * Ensures that an empty file with given name exists.
 */
void init_file(const char *filename) {
    printf("[Main] Initializing file %s...", FILENAME);
    fflush(stdout);
    int fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd<0) handle_error("error while initializing file");
    close(fd);
    printf("closed...file correctly initialized!!!\n");
}

/*
 * Create a named semaphore with a given name, mode and initial value.
 * Also, tries to remove any pre-existing semaphore with the same name.
 */
sem_t *create_named_semaphore(const char *name, mode_t mode, unsigned int value) {
    printf("[Main] Creating named semaphore %s...", name);
    fflush(stdout);
    
    sem_t *ret = malloc(sizeof(sem_t));
    ret = sem_open(name, O_CREAT | O_EXCL, mode, value); // inizializzo a numero di processi (per sincronizzare n processi figlio)
    if (ret == NULL) handle_error("errore apertura semaforo\n");

    printf("done!!!\n");
    return ret;
}



void parseOutput() {
    // identify the child that accessed the file most times
    int* access_stats = calloc(n, sizeof(int)); // initialized with zeros
    printf("[Main] Opening file %s in read-only mode...", FILENAME);
	fflush(stdout);
    int fd = open(FILENAME, O_RDONLY);
    if (fd < 0) handle_error("error while opening output file");
    printf("ok, reading it and updating access stats...");
	fflush(stdout);

    size_t read_bytes;
    int index;
    do {
        read_bytes = read(fd, &index, sizeof(int));
        if (read_bytes > 0)
            access_stats[index]++;
    } while(read_bytes > 0);
    printf("ok, closing it...");
	fflush(stdout);

    close(fd);
    printf("closed!!!\n");

    int max_child_id = -1, max_accesses = -1;
    for (int i = 0; i < n; i++) {
        printf("[Main] Child %d accessed file %s %d times\n", i, FILENAME, access_stats[i]);
        if (access_stats[i] > max_accesses) {
            max_accesses = access_stats[i];
            max_child_id = i;
        }
    }
    printf("[Main] ===> The process that accessed the file most often is %d (%d accesses)\n", max_child_id, max_accesses);
    free(access_stats);
}

void* thread_function(void* x) {
    thread_args_t *args = (thread_args_t*)x;

    /* TODO: protect the critical section using semaphore(s) as needed */
    int ret = sem_wait(&sem);
    if (ret == -1) handle_error("errore sem_wait\n");

    // open file, write child identity and close file
    int fd = open(FILENAME, O_WRONLY | O_APPEND);
    if (fd < 0) handle_error("error while opening file");
    printf("[Child#%d-Thread#%d] File %s opened in append mode!!!\n", args->child_id, args->thread_id, FILENAME);	

    write(fd, &(args->child_id), sizeof(int));
    printf("[Child#%d-Thread#%d] %d appended to file %s opened in append mode!!!\n", args->child_id, args->thread_id, args->child_id, FILENAME);	

    close(fd);
    printf("[Child#%d-Thread#%d] File %s closed!!!\n", args->child_id, args->thread_id, FILENAME);

    int ret = sem_post(&sem);
    if (ret == -1) handle_error("errore sem_post\n");

    free(x);
    pthread_exit(NULL);
}

void mainProcess() {
    /* TODO: the main process waits for all the children to start,
     * it notifies them to start their activities, and sleeps
     * for some time t. Once it wakes up, it notifies the children
     * to end their activities, and waits for their termination.
     * Finally, it calls the parseOutput() method and releases
     * any shared resources. */
    for (int i = 0; i < n; ++i)
    {
        sem_wait(process_sem); // aspetta sem_signal da tutti i figli che lo mandano quando startano
    }
    for (int i = 0; i < n; ++i)
    {
        sem_post(process_sem); // fa sem_signal a tutti i figli dicendogli di iniziare le loro attività
    }
    sleep(t);
    for (int i = 0; i < n; ++i)
    {
        sem_post(process_sem); // fa sem_signal a tutti i figli dicendogli di terminare le loro attività
    }// forse servono due semafori
    for (int i = 0; i < n; ++i)
    {
        
    }
    parseOutput();
    munmap(pt, SIZE);
    close(fd_shm);
    shm_unlink(SHM_NAME);

    sem_close(SEM_NAME);
    sem_unlink(SEM_NAME);
}

void childProcess(int child_id) {
    /* TODO: each child process notifies the main process that it
     * is ready, then waits to be notified from the main in order
     * to start. As long as the main process does not notify a
     * termination event [hint: use sem_getvalue() here], the child
     * process repeatedly creates m threads that execute function
     * thread_function() and waits for their completion. When a
     * notification has arrived, the child process notifies the main
     * process that it is about to terminate, and releases any
     * shared resources before exiting. */
}

int main(int argc, char **argv) {
    // arguments
    if (argc > 1) n = atoi(argv[1]);
    if (argc > 2) m = atoi(argv[2]);
    if (argc > 3) t = atoi(argv[3]);

    // initialize the file
    init_file(FILENAME);

    /* TODO: initialize any semaphore needed in the implementation, and
     * create N children where the i-th child calls childProcess(i); 
     * initialize the shared memory (create it, set its size and map it in the 
     * memory), then the main process executes function mainProcess() once 
     * all the children have been created */
    process_sem = create_named_semaphore(SEM_NAME, 0666, n);
    int     ret = sem_init(&sem, 0, m);
    if (ret == -1) handle_error("errore inizializzazione semaforo\n");

    ret = shm_unlink(SHM_NAME);
    if (ret == -1) handle_error("errore unlinking\n");
    fd_shm = shm_open(SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0600);
    if (fd_shm < 0) handle_error("errore apertura\n");
    if (ftruncate(fd_shm, SIZE == -1)) handle_error("errore ftruncate\n");
    pt = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
    if (!pt) handle_error("errore mapping\n");

    for (int i = 0; i < n; ++i)
    {
        pid_t pid = fork(); // definisco ogni volta la var?
        if (pid == -1) handle_error("errore fork\n");
        if (pid == 0)
        {
            childProcess(i);
        }
    }
    mainProcess();

    exit(EXIT_SUCCESS);
}