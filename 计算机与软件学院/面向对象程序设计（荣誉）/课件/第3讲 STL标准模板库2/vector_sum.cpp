  //����n������n�����������ۺͼ��۳ˡ�

  #include <iostream>
  #include <vector>
  #include <algorithm>
  using namespace std;

  int main()
  {
      vector<int>  vec;
      int   n,e;

      cin>>n;

      while(n--)
      {
          cin>>e;
          vec.push_back(e);
      }

      int sum=0, mul=1;
      for_each(vec.begin(),vec.end(),[&sum](int x){sum+=x;});
      for_each(begin(vec),end(vec),[&mul](int x){mul*=x;});
      cout<<"sum = "<<sum<<endl;
      cout<<"mul = "<<mul<<endl;

  }
