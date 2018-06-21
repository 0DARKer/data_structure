#include<stdio.h>
#include<limits.h>
#define V 5
int minKey(int key[],bool mstSet[]){//这个函数在边键值key数组和生成树节点集mstSet中得到从生成树到邻接节点的最短路径.返回这个节点.
    int min=INT_MAX,min_index;
    for(int v=0;v<V;v++)
        if(mstSet[v]==false && key[v]<min)
            min=key[v],min_index=v;
    return min_index;
}
void printMST(int parent[],int n,int graph[V][V]){
    printf("Edge Weight\n");
    for(int i=1;i<V;i++)
        printf("%d-%d  %d \n",parent[i],i,graph[i][parent[i]]);

}
void primMST(int graph[V][V]){//这个函数可以使用参数表中的邻接矩阵维护一个parent数组,从parent数组可以得到一个最小生成树(MST),最后打印出来
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i=0;i<V;i++)
        key[i]=INT_MAX,mstSet[i]=false;
    key[0]=0;
    parent[0]=-1;
    

    for (int count=0;count <V-1;count++){
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]&&mstSet[v]==false && graph[u][v]<key[v])
                parent[v]=u,key[v]=graph[u][v];
        }
    }
    printMST(parent,V,graph);
}
int main(){
    int graph[V][V]={{0,2,0,6,0},
                     {2,0,3,8,5},
                     {0,3,0,0,7},
                     {6,8,0,0,9},
                     {0,5,7,9,0}
                    }   ;
    primMST(graph);
    return 0;
    
}
