// Solve Random 15 Puzzles : Nigel Galloway - October 11th., 2017
const int Nr[]{3,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3}, Nc[]{3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2};
using N = std::tuple<int,int,unsigned long,std::string,int>;
void    fN(const N,const int);
const N fI(const N n){
  int           g = (11-std::get<1>(n)-std::get<0>(n)*4)*4;
  unsigned long a = std::get<2>(n)&((unsigned long)15<<g);
  return N (std::get<0>(n)+1,std::get<1>(n),std::get<2>(n)-a+(a<<16),std::get<3>(n)+"d",(Nr[a>>g]<=std::get<0>(n))?std::get<4>(n):std::get<4>(n)+1);
} 
const N fG(const N n){
  int           g = (19-std::get<1>(n)-std::get<0>(n)*4)*4;
  unsigned long a = std::get<2>(n)&((unsigned long)15<<g);
  return N (std::get<0>(n)-1,std::get<1>(n),std::get<2>(n)-a+(a>>16),std::get<3>(n)+"u",(Nr[a>>g]>=std::get<0>(n))?std::get<4>(n):std::get<4>(n)+1);
} 
const N fE(const N n){
  int           g = (14-std::get<1>(n)-std::get<0>(n)*4)*4;
  unsigned long a = std::get<2>(n)&((unsigned long)15<<g);
  return N (std::get<0>(n),std::get<1>(n)+1,std::get<2>(n)-a+(a<<4),std::get<3>(n)+"r",(Nc[a>>g]<=std::get<1>(n))?std::get<4>(n):std::get<4>(n)+1);
} 
const N fL(const N n){
  int           g = (16-std::get<1>(n)-std::get<0>(n)*4)*4;
  unsigned long a = std::get<2>(n)&((unsigned long)15<<g);
  return N (std::get<0>(n),std::get<1>(n)-1,std::get<2>(n)-a+(a>>4),std::get<3>(n)+"l",(Nc[a>>g]>=std::get<1>(n))?std::get<4>(n):std::get<4>(n)+1);
}
void    fZ(const N n, const int g){
  if (std::get<2>(n)==0x123456789abcdef0){
    int g{};for (char a: std::get<3>(n)) ++g;
    std::cout<<"Solution found with "<<g<<" moves: "<<std::get<3>(n)<<std::endl; exit(0);}
  if (std::get<4>(n) <= g) fN(n,g);
}
void fN(const N n, const int g){
  const int i{std::get<0>(n)}, e{std::get<1>(n)}, l{std::get<3>(n).back()};
  switch(i){case  0: switch(e){case  0: switch(l){case 'l': fZ(fI(n),g); return;
                                                  case 'u': fZ(fE(n),g); return;
                                                  default : fZ(fE(n),g); fZ(fI(n),g); return;}
                               case  3: switch(l){case 'r': fZ(fI(n),g); return;
                                                  case 'u': fZ(fL(n),g); return;
                                                  default : fZ(fL(n),g); fZ(fI(n),g); return;}
                               default: switch(l){case 'l': fZ(fI(n),g); fZ(fL(n),g); return;
                                                  case 'r': fZ(fI(n),g); fZ(fE(n),g); return;
                                                  case 'u': fZ(fE(n),g); fZ(fL(n),g); return;
                                                  default : fZ(fL(n),g); fZ(fI(n),g); fZ(fE(n),g); return;}}
            case  3: switch(e){case  0: switch(l){case 'l': fZ(fG(n),g); return;
                                                  case 'd': fZ(fE(n),g); return;
                                                  default : fZ(fE(n),g); fZ(fG(n),g); return;}
                               case  3: switch(l){case 'r': fZ(fG(n),g); return;
                                                  case 'd': fZ(fL(n),g); return;
                                                  default : fZ(fL(n),g); fZ(fG(n),g); return;}
                               default: switch(l){case 'l': fZ(fG(n),g); fZ(fL(n),g); return;
                                                  case 'r': fZ(fG(n),g); fZ(fE(n),g); return;
                                                  case 'd': fZ(fE(n),g); fZ(fL(n),g); return;
                                                  default : fZ(fL(n),g); fZ(fG(n),g); fZ(fE(n),g); return;}}
            default: switch(e){case  0: switch(l){case 'l': fZ(fI(n),g); fZ(fG(n),g); return;
                                                  case 'u': fZ(fE(n),g); fZ(fG(n),g); return;
                                                  case 'd': fZ(fE(n),g); fZ(fI(n),g); return;
                                                  default : fZ(fE(n),g); fZ(fI(n),g); fZ(fG(n),g); return;}
                               case  3: switch(l){case 'd': fZ(fI(n),g); fZ(fL(n),g); return;
                                                  case 'u': fZ(fL(n),g); fZ(fG(n),g); return;
                                                  case 'r': fZ(fI(n),g); fZ(fG(n),g); return;
                                                  default : fZ(fL(n),g); fZ(fI(n),g); fZ(fG(n),g); return;}
                               default: switch(l){case 'd': fZ(fI(n),g); fZ(fL(n),g); fZ(fE(n),g); return;
                                                  case 'l': fZ(fI(n),g); fZ(fL(n),g); fZ(fG(n),g); return;
                                                  case 'r': fZ(fI(n),g); fZ(fE(n),g); fZ(fG(n),g); return;
                                                  case 'u': fZ(fE(n),g); fZ(fL(n),g); fZ(fG(n),g); return;
                                                  default : fZ(fL(n),g); fZ(fI(n),g); fZ(fE(n),g); fZ(fG(n),g); return;}}}
}
void Solve(N n){for(int g{};;++g) fN(n,g);}

int main (){
  N start(2,0,0xfe169b4c0a73d852,"",0);
  Solve(start);
}
