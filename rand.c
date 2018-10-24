int* spiralOrder(const int** A, int n11, int n12, int *len1) {
    int T=0;
    int B = n11-1;
    int L =0;
    int R = n12-1;
    int dir=0;
    int i=0;
    *len1 = n11*n12;
    int *res;
    res = (int*) malloc(*len1 * sizeof(int));
    int j =0;
    while(T<=B && L <=R)
    {
        if(dir==0)
        {
            for (i=L;i<=R;i++)
            {
                res[j] = A[T][i];
                //printf("%d\n",A[T][i]);
                j++;
            }
            T++;dir=1;
        }
        else if(dir == 1)
        {
            for(i=T;i<=B;i++)
            {
                res[j] = A[i][R];
                //printf("%d\n",A[i][R]);
                j++;
            }
            R--; dir =2;
        }
        else if(dir ==2)
        {
            for(i=R;i>=L;i--)
            {
                res[j] = A[B][i];
                //printf("%d\n",A[B][i]);
                j++;
            }
            B--;dir=3;
        }
        else if(dir ==3)
        {
            for(i=B;i>=T;i--)
            {
                res[j] = A[i][L];
                //printf("%d\n",A[i][L]);
                j++;
            }
            L++; dir =0;
        }
    }
    return res;
}
