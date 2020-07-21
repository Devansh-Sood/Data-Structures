/*tree traversal in zig zag order*/

public void spiralWithTwoStack(Node root) {
        if (root == null) {
            return;
        }
        stack<Node> s1 ;
        stack<Node> s2 ;
        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                root = s1.top();
		s1.pop();
                cout<<root.data<<" ";
                if (root.left != null) {
                    s2.push(root.left);
                }
                if (root.right != null) {
                    s2.push(root.right);
                }
            }
            while (!s2.empty()) {
                root = s2.top();
		s2.pop();
                cout<<root.data<<" ";
                if (root.right != null) {
                    s1.push(root.right);
                }
                if (root.left != null) {
                    s1.push(root.left);
                }
            }
        }
    }