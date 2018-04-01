#include <iostream>
#include <vector>
using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int x,int y):x(x),y(y){}
	string info(){
		return to_string(x)+":"+to_string(y);
	}
};

int N;
vector<Point> arr;
int area;

void pointSX(Point &a,Point &b){
	Point tmp = a;
	if(b.x<a.x){
		a.x=b.x;
		a.y=b.y;
		b.x=tmp.x;
		b.y=tmp.y;
	}
}

void pointSY(Point &a,Point &b){
	Point tmp = a;
	if(b.y<a.y){
		a.x=b.x;
		a.y=b.y;
		b.x=tmp.x;
		b.y=tmp.y;
	}
}

int duplicateArea(Point a,Point b){
	int diffX,diffY;
	pointSX(a,b);
	cout<<a.info()<<" "<<b.info()<<endl;
	diffX=a.x+10-b.x;
	pointSY(a,b);
	cout<<a.info()<<" "<<b.info()<<endl;
	diffY=a.y+10-b.y;
	return diffX*diffY>0?diffX*diffY:0;
}

int main(){
  int tx,ty;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tx>>ty;
		arr.push_back(Point(tx,ty));
	}
	area=N*100;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			area-=duplicateArea(arr[i],arr[j]);
		}
	}
	cout<<area<<endl;
	return 0;
}
