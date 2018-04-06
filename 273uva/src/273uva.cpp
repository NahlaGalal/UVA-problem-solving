#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y){}
    Point():x(0), y(0){}
    Point& operator=(const Point& o){
    	x = o.x;
    	y = o.y;
    	return *this;
    }
    Point& operator+=(const Point& o){
		x += o.x;
		y += o.y;
		return *this;
	}
};

Point operator-(const Point &a){
    return Point(-a.x, -a.y);
}
Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
Point operator-(const Point &a, const Point &b){
    return Point(a.x-b.x, a.y-b.y);
}
double operator^(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}
double operator*(const Point &a, const Point &b){
    return a.x*b.x + a.y*b.y;
}
double abs(const Point &p){
    return p*p;
}
double norm(const Point &p){
    return sqrt(p*p);
}
Point operator*(const double factor, const Point & p){
    return Point(factor * p.x, factor * p.y);
}
Point operator*(const Point & p, const double factor){
    return Point(factor * p.x, factor * p.y);
}

struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a){}
    Segment():a(), ab(){}

    Point b () const {
        return a + ab;
    }
};

bool inter(const Segment& s1, const Segment &s2){
    if((s1.ab ^ s2.ab) == 0)return 0; // parallel
    double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
    if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1)return 0;// does not intersect
    return 1;
}
bool onsegment(const Segment& r, const Point& p){
    return ((p - r.a) ^ r.ab) == 0 && ((p - r.a) * (p - r.b())) <= 0;
}

vector<vector <int> > adjlist(101) ;
vector<bool> visited(101) ;
bool bl=false ;

bool dfs(int node, int b){
	visited[node] = true ;
	for(int i=0 ; i<adjlist[node].size() ; i++){
		int child = adjlist[node][i] ;
//		cout<<"Node: "<<node<<" Child: "<<child<<endl ;
		if(child == b){
			bl=true ;
			break ;
		}
		if(!visited[child]) dfs(child, b) ;
	}
	return bl ;
}

const double PI = acos(-1) ;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int t;
	cin>>t ;
	while(t--){
		int n ;
		cin>>n ;
		int arr[n][4] ;
		for(int i=0 ; i<adjlist.size() ; i++) adjlist[i].clear() ;
		for(int i=0 ; i<n ; i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3] ;
		for(int i=0 ; i<n ; i++){
			Point p1(arr[i][0], arr[i][1]), p2(arr[i][2], arr[i][3]);
			Segment s1(p1,p2) ;
			for(int j=i+1 ; j<n ; j++){
				Segment s2(Point(arr[j][0], arr[j][1]), Point(arr[j][2], arr[j][3])) ;
				if(inter(s1,s2) || onsegment(s2,p1) || onsegment(s2,p2)){
					adjlist[i].push_back(j) ;
					adjlist[j].push_back(i) ;
				}
			}
		}
		int a,b ;
		while(cin>>a>>b){
			if(a==0 && b==0) break;
			for(int i=0 ; i<=100 ; i++) visited[i]=false;
			bl=false ;
			if(a==b || dfs(a-1, b-1)) cout<<"CONNECTED"<<endl ;
			else cout<<"NOT CONNECTED"<<endl ;
		}
		if(t) cout<<endl;
	}
	return 0 ;
}
