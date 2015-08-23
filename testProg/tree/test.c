node * findLCA(node *root, int e1, int e2, bool v1, bool v2)
{
	if(root==NULL)
	  retunr NULL:
	if(root->data ==e1)
	{
		e1=true;	
		return root;
	}
	if(root->data ==e2)
	{
		e2=true;
		return root;
	}
	node *left = findLCA(root->left, e1, e2, v1, v2);
	node *right = findLCA(root->right, e1, e2, v1, v2);
	if(left & right)
	  return root;
	if(left!=NULL)?left:right;
}
