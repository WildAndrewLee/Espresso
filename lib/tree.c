struct node {
	int size;
	string token;
	node* children;
};

//Interface
node newNode(string token, int size);

//Implementations
node newNode(string token, int size){
	assert(token);
	assert(size >= 0);

	node n = emalloc(sizeof(*n));
	n->token = token;

	n->children = emalloc(sizeof(struct node) * size);

	n->size = size;

	return n;
}