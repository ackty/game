// Solve Random 15 Puzzles : Nigel Galloway - October 18th., 2017
class fifteenSolver{
  const int Nr[16]{3,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3}, Nc[16]{3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2}, i{1}, g{8}, e{2}, l{4};
  int n{},_n{}, N0[85]{},N3[85]{},N4[85]{};
  unsigned long N2[85]{};
  const bool fY(){
    if (N2[n]==0x123456789abcdef0) return true; 
    if (N4[n]<=_n) return fN();
    return false;
  }
  const bool fZ(const int w){
    if ((w&i)>0){fI(); if (fY()) return true;--n;}
    if ((w&g)>0){fG(); if (fY()) return true;--n;}
    if ((w&e)>0){fE(); if (fY()) return true;--n;}
    if ((w&l)>0){fL(); if (fY()) return true;--n;}
    return false;
  }
  const bool fN(){
    switch(N0[n]){case  0:          switch(N3[n]){case 'l': return fZ(i);
                                                  case 'u': return fZ(e);
                                                  default : return fZ(i+e);}
                  case  3:          switch(N3[n]){case 'r': return fZ(i);
                                                  case 'u': return fZ(l);
                                                  default : return fZ(i+l);}
                  case  1: case  2: switch(N3[n]){case 'l': return fZ(i+l);
                                                  case 'r': return fZ(i+e);
                                                  case 'u': return fZ(e+l);
                                                  default : return fZ(l+e+i);}
                  case 12:          switch(N3[n]){case 'l': return fZ(g);
                                                  case 'd': return fZ(e);
                                                  default : return fZ(e+g);}
                  case 15:          switch(N3[n]){case 'r': return fZ(g);
                                                  case 'd': return fZ(l);
                                                  default : return fZ(g+l);}
                  case 13: case 14: switch(N3[n]){case 'l': return fZ(g+l);
                                                  case 'r': return fZ(e+g);
                                                  case 'd': return fZ(e+l);
                                                  default : return fZ(g+e+l);}
                  case  4: case 8:  switch(N3[n]){case 'l': return fZ(i+g);
                                                  case 'u': return fZ(g+e);
                                                  case 'd': return fZ(i+e);
                                                  default : return fZ(i+g+e);}
                  case  7: case 11: switch(N3[n]){case 'd': return fZ(i+l);
                                                  case 'u': return fZ(g+l);
                                                  case 'r': return fZ(i+g);
                                                  default : return fZ(i+g+l);}
                  default:          switch(N3[n]){case 'd': return fZ(i+e+l);
                                                  case 'l': return fZ(i+g+l);
                                                  case 'r': return fZ(i+g+e);
                                                  case 'u': return fZ(g+e+l);
                                                  default : return fZ(i+g+e+l);}}
  }
  void fI(){
    const int           g = (11-N0[n])*4;
    const unsigned long a = N2[n]&((unsigned long)15<<g);
    N0[n+1]=N0[n]+4; N2[n+1]=N2[n]-a+(a<<16); N3[n+1]='d'; N4[n+1]=N4[n]+(Nr[a>>g]<=N0[n++]/4?0:1);
  } 
  void fG(){
    const int           g = (19-N0[n])*4;
    const unsigned long a = N2[n]&((unsigned long)15<<g);
    N0[n+1]=N0[n]-4; N2[n+1]=N2[n]-a+(a>>16); N3[n+1]='u'; N4[n+1]=N4[n]+(Nr[a>>g]>=N0[n++]/4?0:1);
  } 
  void fE(){
    const int           g = (14-N0[n])*4;
    const unsigned long a = N2[n]&((unsigned long)15<<g);
    N0[n+1]=N0[n]+1; N2[n+1]=N2[n]-a+(a<<4); N3[n+1]='r'; N4[n+1]=N4[n]+(Nc[a>>g]<=N0[n++]%4?0:1);
  } 
  void fL(){
    const int           g = (16-N0[n])*4;
    const unsigned long a = N2[n]&((unsigned long)15<<g);
    N0[n+1]=N0[n]-1; N2[n+1]=N2[n]-a+(a>>4); N3[n+1]='l'; N4[n+1]=N4[n]+(Nc[a>>g]>=N0[n++]%4?0:1);
  }
public:
  fifteenSolver(int n, unsigned long g){N0[0]=n; N2[0]=g; N4[0]=0;}
  void Solve(){
    if (fN()) {std::cout<<"Solution found in "<<n<<" moves: "; for (int g{1};g<=n;++g) std::cout<<(char)N3[g]; std::cout<<std::endl;}
    else {n=0; ++_n; Solve();}
  }
};

int main (){
  fifteenSolver start(8,0xfe169b4c0a73d852);
  start.Solve();
}
