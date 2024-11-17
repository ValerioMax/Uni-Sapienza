#include "common.h"

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>


// data array
int * data;
/** COMPLETE THE FOLLOWING CODE BLOCK
*
* Add any needed resource 
**/
int   sm_fd;
sem_t *sem_req, *sem_wrk;

int request() {
  /** COMPLETE THE FOLLOWING CODE BLOCK
  *
  * map the shared memory in the data array
  **/
  data = (int *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, sm_fd, 0);

  printf("request: mapped address: %p\n", data);

  int i;
  for (i = 0; i < NUM; ++i) {
    data[i] = i;
  }
  printf("request: data generated\n");

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Signal the worker that it can start the elaboration
    * and wait it has terminated
    **/
  sem_post(sem_wrk);
  printf("request: acquire updated data\n");
  sem_wait(sem_req);
  printf("request: updated data:\n");
  for (i = 0; i < NUM; ++i) {
    printf("%d\n", data[i]);
  }

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Release resources
    **/
  munmap(data, SIZE);


  return EXIT_SUCCESS;
}

int work() {

  /** COMPLETE THE FOLLOWING CODE BLOCK
  *
  * map the shared memory in the data array
  **/
  data = (int *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, sm_fd, 0);

  printf("worker: mapped address: %p\n", data);

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Wait that the request() process generated data
    **/
  printf("worker: waiting initial data\n");
  sem_wait(sem_wrk);
  printf("worker: initial data acquired\n");

  printf("worker: update data\n");
  int i;
  for (i = 0; i < NUM; ++i) {
    data[i] = data[i] * data[i];
  }

  printf("worker: release updated data\n");

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Signal the requester that elaboration terminated
    **/
  sem_post(sem_req);

  /** COMPLETE THE FOLLOWING CODE BLOCK
   *
   * Release resources
   **/
  munmap(data, SIZE);

  return EXIT_SUCCESS;
}



int main(int argc, char **argv){

  /** COMPLETE THE FOLLOWING CODE BLOCK
  *
  * Create and open the needed resources 
  **/
  sem_unlink(SEM_NAME_REQ);
  sem_unlink(SEM_NAME_WRK);
  sem_req = sem_open(SEM_NAME_REQ, O_CREAT | O_EXCL, 0600, 0);
  sem_wrk = sem_open(SEM_NAME_WRK, O_CREAT | O_EXCL, 0600, 0);

  shm_unlink(SHM_NAME);
  sm_fd = shm_open(SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0600);  
  ftruncate(sm_fd, SIZE);
  
  int ret;
  pid_t pid = fork();
  if (pid == -1) {
      handle_error("main: fork");
  } else if (pid == 0) {
      work();
      _exit(EXIT_SUCCESS);
  }

  request();
  int status;
  ret = wait(&status);
  if (ret == -1)
    handle_error("main: wait");
  if (WEXITSTATUS(status)) handle_error_en(WEXITSTATUS(status), "request() crashed");


  /** COMPLETE THE FOLLOWING CODE BLOCK
  *
  * Close and release resources
  **/
  sem_close(sem_req);
  sem_unlink(SEM_NAME_REQ);
  sem_close(sem_wrk);
  sem_unlink(SEM_NAME_WRK);

  close(sm_fd);
  shm_unlink(SHM_NAME);

  _exit(EXIT_SUCCESS);

}
