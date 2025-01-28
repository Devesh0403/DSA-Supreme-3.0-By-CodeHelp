bool isPossible(int a,int b)
    {
        if((a==2&&b!=2)||(b==2&&a!=2))return true;
        
        else return false;
        
    }

    // As inorder is always required to construct a BT, 
    // Whether Preorder is Givern or PostOrder, it doesnt matter