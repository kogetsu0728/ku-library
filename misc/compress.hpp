#pragma once

template<class T,class C=less<T>>
class Compress{
	private:
		BuildChecker build_checker;
		vector<T> vec;

	public:
		Compress(): build_checker(), vec() {}

		void push(const T x){
			build_checker.before();

			vec.push_back(x);
		}

		void build(){
			build_checker.build();

			sort(vec.begin(), vec.end(), C());
			vec.erase(unique(vec.begin(),vec.end()),vec.end());
		}

		size_t size() const {
			build_checker.after();

			return vec.size();
		}

		T nth(const int i) const {
			build_checker.after();

			assert(0<=i && i<int(vec.size()));
			return vec[i];
		}

		int get(const T x) const {
			build_checker.after();

			int ng=-1, ok=int(vec.size())-1;
			while(1<ok-ng){
				int mid=(ok+ng)/2;
				if(!C()(vec[mid],x)) ok=mid;
				else ng=mid;
			}
			return ok;
		}

		bool contains(const T x) const {
			build_checker.after();

			return nth(get(x))==x;
		}
};
