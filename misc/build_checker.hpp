class BuildChecker{
	private:
		bool built;

	public:
		BuildChecker(): built(false){}
		
		void before() const {
			assert(built==false);
		}

		void after() const {
			assert(built==true);
		}

		void build(){
			this->before();
			built = true;
		}
};
