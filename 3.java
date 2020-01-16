
static public ArrayList<Integer> GetLeastNumbers_Solution1(int[] input, int k) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (input==null||input.length==0||input.length<k) {
            return res;
        }
        int []maxHeap = new int[k];
        for (int i = 0; i < maxHeap.length; i++) {
            maxHeap[i] = input[i];
        }
        for (int i = (maxHeap.length-1)/2; i >=0 ; i--) {
            adjustHeap(maxHeap, i);
        }
        for (int i = k; i <input.length ; i++) {
            if (maxHeap[0]>input[i]) {
                maxHeap[0] = input[i];
                adjustHeap(maxHeap, 0);
            }
        }
        for (int i = 0; i < maxHeap.length; i++) {
            res.add(maxHeap[i]);
        }
        return res;
    }
    static void adjustHeap(int maxHeap[],int i){
        int index = i;
        int lchild=2*i+1;       //i的左孩子节点序号 
        int rchild=2*i+2;     //i的右孩子节点序号 
        if(index<=(maxHeap.length-1)/2) {
            //寻找子节点中最大的节点
            if (lchild<maxHeap.length&&maxHeap[index]<maxHeap[lchild]) {
                index = lchild;
            }
            if (rchild<maxHeap.length&&maxHeap[index]<maxHeap[rchild]) {
                index = rchild;
            }
            if (i!=index) {
                //将节点与最大的子节点交换
                int tmp = maxHeap[index];
                maxHeap[index] = maxHeap[i];
                maxHeap[i] = tmp;
                //交换后，子树可能不满足最大推，递归调整。
                adjustHeap(maxHeap, index);
            }
        }
       