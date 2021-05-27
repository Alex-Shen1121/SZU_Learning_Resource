  //ʵ��һ�����İ�λ�ò��롢ɾ��������Ԫ�ء�

  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  //�����
  void display(vector<int> v)
  {
      for(auto x:v)
        cout<<x<<" ";
      cout<<endl;
  }

  //��λ�ò��룬����λ��1-����+1
  int insert(vector<int> &v,int i,int e)
  {
      if(i<1 || i>(int)v.size()+1)
        return 0;
      v.insert(begin(v)+i-1,e);
      return 1;
  }

  //��Ԫ��ֵɾ��Ԫ��
  int deleteelem(vector<int> &v,int e)
  {
        for(auto it = begin(v); it!=end(v); it++)
            if(*it == e)                     //����Ԫ��
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

      //��λ�ò���
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

      //��Ԫ��ֵɾ��
      cout<<"---------delete e---------��<<endl;
      cin>>m;
      while(m--)
      {
          cin>>e;
          if(!deleteelem(vec,e))
            cout<<"error!"<<endl;
          else
            display(vec);
      }

      //����Χɾ��
      cout<<"----------delete range------------"<<endl;
      int first,last;
      cin>>first>>last;               //stl�л��ڷ�Χ�Ĳ������ǰ뿪����[first,last)
      vec.erase(begin(vec)+n,begin(vec)+m);
      display(vec);

      //ɾ�����һ��Ԫ��
      cout<<"------------pop back--------------"<<endl;
      vec.pop_back();  //ɾ�����һ��Ԫ��
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

