#pragma once

template<class T>
class CumulativeSum2d{
	private:
		int h, w;
		vector<vector<T>> v;

	public:
		CumulativeSum2d():CumulativeSum2d(0,0){}
		CumulativeSum2d(int _h, int _w, T _e=0):
			h(_h), w(_w), v(_h+1,vector<T>(_w+1,_e)){}

		void add(int y, int x, T d){
			v[y+1][x+1] += d;
		}

		void add(int y1, int x1, int y2, int x2, T d){
			add(y1, x1, d);
			add(y1, x2, -d);
			add(y2, x1, -d);
			add(y2, x2, d);
		}

		void build(){
			for(int y=1; y<=h; y++){
				for(int x=1; x<=w; x++){
					v[y][x] += v[y][x-1]+v[y-1][x]-v[y-1][x-1];
				}
			}
		}

		T get(int y, int x) const {
			return v[y+1][x+1];
		}

		T sum(int y1, int x1, int y2, int x2) const {
			return v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];
		}
};
