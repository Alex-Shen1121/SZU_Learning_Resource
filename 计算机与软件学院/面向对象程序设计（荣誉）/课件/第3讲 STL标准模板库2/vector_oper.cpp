  //实现一组数的按位置插入、删除、查找元素。

  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  //输出数
  void display(vector<int> v)
  {
      for(auto x:v)
        cout<<x<<" ";
      cout<<endl;
  }

  //按位置插入，插入位置1-长度+1
  int insert(vector<int> &v,int i,int e)
  {
      if(i<1 || i>(int)v.size()+1)
        return 0;
      v.insert(begin(v)+i-1,e);
      return 1;
  }

  //按元素值删除元素
  int deleteelem(vector<int> &v,int e)
  {
        for(auto it = begin(v); it!=end(v); it++)
            if(*it == e)                     //查找元素
            {
                v.erase(it);
                return 1;
            }
        return 0;
  }


  int main()
  {
      vector<int>  vec;
      int   n,e,m,index;

      cin>>n;

      while(n--)
      {
          cin>>e;
          vec.push_back(e);
      }
      display(vec);

      //按位置插入
      cout<<"------insert-----------------"<<endl;
      cin>>m;
      while(m--)
      {
          cin>>index>>e;
          if(!insert(vec,index,e))
            cout<<"error!"<<endl;
          else
            display(vec);
      }

      //按元素值删除
      cout<<"---------delete e---------“<<endl;
      cin>>m;
      while(m--)
      {
          cin>>e;
          if(!deleteelem(vec,e))
            cout<<"error!"<<endl;
          else
            display(vec);
      }

      //按范围删除
      cout<<"----------delete range------------"<<endl;
      int first,last;
      cin>>first>>last;               //stl中基于范围的操作都是半开区间[first,last)
      vec.erase(begin(vec)+n,begin(vec)+m);
      display(vec);

      //删除最后一个元素
      cout<<"------------pop back--------------"<<endl;
      vec.pop_back();  //删除最后一个元素
      display(vec);

  }


  /*
  4 10 20 30 40
  5
  0 15
  1 15
  2 55
  7 100
  10 14
  3
  15
  30
  40
  2 3
  */

