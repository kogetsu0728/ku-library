#pragma once

template<class T,class C=less<T>>
class Compress{
	private:
		vector<T> v;

	public:
		Compress(){}

		void push(const T x){
			v.push_back(x);
		}

		void build(){
			sort(v.begin(), v.end(), C());
			v.erase(unique(v.begin(),v.end()),v.end());
		}

		size_t size() const {
			return v.size();
		}

		T nth(const int i) const {
			assert(0<=i && i<int(v.size()));
			return v[i];
		}

		int get(const T x) const {
			int ng=-1, ok=int(v.size())-1;
			while(1<ok-ng){
				int mid=(ok+ng)/2;
				if(!C()(v[mid],x)) ok=mid;
				else ng=mid;
			}
			return ok;
		}

		bool count(const T x) const {
			return nth(get(x))==x;
		}
};
