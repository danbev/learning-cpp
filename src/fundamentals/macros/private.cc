int GetDebugSymbols();

#define private friend int GenDebugSymbols(); private

class Something {
 private: 
   int x;
};

//#define bajja friend int Doit(); xyz

//bajja
//
int GetDebugSymbols() {
  return 10;
}

//int testing(); private
