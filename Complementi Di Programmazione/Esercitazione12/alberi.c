#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* CreateNode(int data){
	struct Node* NewNode = (struct Node*) malloc(sizeof(struct Node));
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}
int max(int a, int b){
	return (a>b) ? a : b;
}
bool estVuoto(struct Node* root){
    return (root == NULL);
}
bool estFoglia(struct Node* root){
    return (sx(root)==NULL && dx(root)==NULL);
}
struct Node* car(struct Node* root){
    return root->data;
}
struct Node* dx(struct Node* root){
    return root->right;
}
struct Node* sx(struct Node* root){
    return root->left;
}
int somma(struct Node* root){
    if (estVuoto(root)){
        return 0;
    }else{
        return car(root) + somma(dx(root)) + somma(sx(root));
    }
}
int contanodi(struct Node* root){
    if (estVuoto(root)){
        return 0;
    }else{
        return 1 + contanodi(sx(root)) + contanodi(dx(root));
    }
}
bool is_equal(struct Node* x, struct Node* y){
	if (x == NULL && y == NULL){
		return true;
	}else{
		return (x&&y) && (x->data == y->data) && is_equal(x->left, y->left) && is_equal(x->right, y->right);
	}
}
bool is_simm(struct Node* x, struct Node* y){
	if (x == NULL && y == NULL){
		return true;
	}else{
		return (x->data == y->data) && is_equal(x->left, y->left) && is_equal(x->right, y->right);
	}
}
bool is_symmetric(struct Node* root){
    if (estVuoto(root)){
        return true;
    }else{
        return is_simm(sx(root),dx(root));
    }
}
int sommaSin(struct Node* root){
	if (root==NULL){
		return 0;
	}else{
		int sum = 0;
		if (root->left!=NULL){
			sum += root->left->data;
			sum += sommaSin(root->left);
		}
		sum += sommaSin(root->right);
		return sum;
	}
}
int sommaDes(struct Node* root){
	if (root==NULL){
		return 0;
	}else{
		int sum = 0;
		if(root->right!=NULL){
			sum += root->right->data;
			sum += sommaDes(root->right);
		}
		sum += sommaDes(root->left);
		return sum;
	}
}
int path_lungo(struct Node* root){
    if (estVuoto(root)){
        return 0;
    }else{
        int left = path_lungo(sx(root));
        int right = path_lungo(dx(root));
        return max(left, right)
    }
}
bool father_greater_son(struct Node* root){
    if (estVuoto(root) && estVuoto(sx(root)) && estVuoto(dx(root))){
        return true;
    }else{
    	if (car(root) > car(sx(root)) && car(root) > car(dx(root))){
			return true;
		}else{
			return (father_greater_son(root->left)) ^ (father_greater_son(root->right));
		}
	}
}
bool is_in_tree(struct Node* root, int e){
    if (estVuoto(root)){
        return false;
    }else{
        if (car(root)==e){
            return true;
        }else{
            return (is_in_tree(sx(root), e)) ^ (is_in_tree(dx(root), e));
        }
    }
}
int altezza(struct Node* root){
    if (estVuoto(root)){
        return 0;
    }else{
        int h_l = altezza(sx(root));
        int h_r = altezza(dx(root));
        return max(h_r, h_l); 
    }
}
void cambia_nodo(struct Node* root, int e){
    if (estVuoto(root) && estVuoto(dx(root)) && estVuoto(sx(root))){
        return;
    }
    if (car(sx(root)) == e){
        root->left->data = car(root);
    }else if(car(dx(root)) == e){
        root->right->data = car(root):
    }else{
        return cambia_nodo(dx(root)) && cambia_nodo(sx(root));
    }

}
int trova_massimo(struct Node* root){
    if (estVuoto(root)){
        return -1;
    }else{

        return max(max(root->data, trova_massimo(root->left)), max(root->data, trova_massimo(root->right)));
    }
}
int conta_dispari(struct Node* root){
    if (estVuoto(root)){
        return 0;
    }else{
        if ((car(root) + car(sx(root)) + car(dx(root)))  % 2 != 0){
            return 1 + conta_dispari(root->left) + conta_dispari(root->right);
        }else{
            return conta_dispari(root->left) + conta_dispari(root->right);
        }   
    }
}
int somma_singoli(struct Node* root){
    if (root==NULL){
        return 0;
    }else{
        if ((root->left != NULL) ^ (root->right !=NULL)){
            return root->data + somma_singoli(root->left) + somma_singoli(root->right);
        }else{
            return somma_singoli(root->left) + somma_singoli(root->right);
        }
    }
}
int cerca_livello_helper(struct Node* node, int value, int level) {
    if (node == NULL) {
        return -1; // Valore non trovato
    }

    if (node->data == value) {
        return level; // Valore trovato
    }

    // Cerca ricorsivamente il valore nei sottoalberi sinistro e destro
    int leftLevel = cerca_livello_helper(node->left, value, level + 1);
    int rightLevel = cerca_livello_helper(node->right, value, level + 1);

    // Restituisce il livello del nodo più a sinistra tra i sottoalberi sinistro e destro
    if (leftLevel != -1) {
        return leftLevel;
    } else {
        return rightLevel;
    }
}
int cerca_livello(struct Node* root, int e){
    return cerca_livello_helper(root, e, 0);
}
int sommaSottoalberoHelper(struct Node* root){
    if (root==NULL){
        return 
    }
    int sumLeft = sommaSottoalberoHelper(node->left);
    int sumRight = sommaSottoalberoHelper(node->right);

    int sumSubtree = sumLeft + sumRight + node->data;
    node->data = sumSubtree;

    return sumSubtree;
}
void somma_sottoalbero(struct Node* root){
    sommaSottoalberoHelper(root);
    return;
}
void swapContent(struct Node* x, struct Node* y){
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}
void scambia_foglie_aux(struct Node* node){
    if (node == NULL || (node->left == NULL && node->right == NULL)) {
            return; 
        }

        // Verifica se le due foglie hanno lo stesso padre
        if (node->left != NULL && node->right != NULL && node->left->left == NULL && node->left->right == NULL &&
            node->right->left == NULL && node->right->right == NULL) {
            swapContent(node->left, node->right); // Scambia il contenuto delle due foglie
        }

        // Scandisci ricorsivamente i sottoalberi sinistro e destro
        scambia_foglie_aux(node->left);
        scambia_foglie_aux(node->right);

}
void scambia_foglie(struct Node* root){
    scambia_foglie_aux(root);
    return;
}
void stampaInOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    stampaInOrder(node->left);
    printf("%d ", node->data);
    stampaInOrder(node->right);
}
void maxFigliLivelloHelper(struct Node* node, int currentLevel, int targetLevel) {
    if (node == NULL) {
        return;
    }

    // Verifica se il nodo si trova al livello target
    if (currentLevel == targetLevel) {
        // Verifica se il nodo ha almeno un figlio
        if (node->left != NULL || node->right != NULL) {
            int maxChildValue = node->data;

            // Verifica e aggiorna il valore massimo tra i figli
            if (node->left != NULL && node->left->data > maxChildValue) {
                maxChildValue = node->left->data;
            }
            if (node->right != NULL && node->right->data > maxChildValue) {
                maxChildValue = node->right->data;
            }

            node->data = maxChildValue; // Modifica il valore del nodo con il massimo tra i valori dei figli
        }
    }

    // Scandisci ricorsivamente i sottoalberi sinistro e destro
    maxFigliLivelloHelper(node->left, currentLevel + 1, targetLevel);
    maxFigliLivelloHelper(node->right, currentLevel + 1, targetLevel);
}
void max_figli_livello(struct Node* root, int level){
    maxFigliLivelloHelper(root,0,level);
}
void ScambiaFoglieLevelHelper(struct Node* node, int current_lev, int level){
    if ((node==NULL) || (node->left == NULL) && (node->right == NULL)){
        return;
    }
    if (currentLevel == targetLevel) {
            // Verifica se il nodo ha entrambi i figli come foglie
            if (node->left != NULL && node->right != NULL && node->left->left == NULL && node->left->right == NULL &&
                node->right->left == NULL && node->right->right == NULL) {
                swapContent(node->left, node->right); // Scambia il contenuto delle due foglie
            }
        }

        // Scandisci ricorsivamente i sottoalberi sinistro e destro
        ScambiaFoglieLevelHelper(node->left, currentLevel + 1, targetLevel);
        ScambiaFoglieLevelHelper(node->right, currentLevel + 1, targetLevel);
}
void scambia_foglie_livello(struct Node* root, int level){
    scambiaFoglieLevelHelper(root, 0, level);
}
int main(){
	struct Node* root = CreateNode(1);
	root->left = CreateNode(2);
	root->right = CreateNode(3);
	root->left->left = CreateNode(4);
	root->right->left = CreateNode(5);
	root->right->right = CreateNode(10);
	root->right->right->left = CreateNode(7);
	root->left->right = CreateNode(6);
	//
    int massimo = trova_massimo(root);
    printf("Massimo: %d\n", massimo);


    return 0;
}