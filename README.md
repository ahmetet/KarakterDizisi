# KarakterDizisi
HasretÇekirdek için c++ kelime öbekleri eklentisi




	private :
		char *_KarakterDizisi;
		unsigned char uzunluk;

	public :
		KarakterDizisi();
		KarakterDizisi(char sagVeri);
		KarakterDizisi(char *sagVeri);
		
		void operator = (const KarakterDizisi KD);
		void operator = (const char sagVeri);
		void operator = (const char *sagVeri);
	
		KarakterDizisi operator + (const char sagVeri);
		KarakterDizisi operator + (const char *sagVeri);
		KarakterDizisi operator + (const KarakterDizisi KD);

		bool operator == (const KarakterDizisi KD);
		bool operator == (const char sagVeri);
		bool operator == (const char *sagVeri);


		friend ostream & operator<<(ostream &b, const KarakterDizisi KD);
		
		int Uzunluk();
		void BuyukHarflereCevir();
		void KucukHarflereCevir();
		char* Al();



