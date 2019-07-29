#include <string>

using namespace std;

struct Lista {
  bool sublista;
  string valorString;
  Lista* valorSublista;
  Lista* proximo;
};

Lista* geraLista() {
  Lista *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7;

  p0 = new Lista;
  p0->sublista = false;
  p0->valorString = "1";
  p0->valorSublista = nullptr;

  p1 = new Lista;
  p1->sublista = false;
  p1->valorString = "2";
  p1->valorSublista = nullptr;

  p2 = new Lista;
  p2->sublista = false;
  p2->valorString = "6";
  p2->valorSublista = nullptr;



  p3 = new Lista;
  p3->sublista = true;
  p3->valorString = "";
  p3->valorSublista = nullptr;


  p4 = new Lista;
  p4->sublista = false;
  p4->valorString = "edu";
  p4->valorSublista = nullptr;

  p5 = new Lista;
  p5->sublista = false;
  p5->valorString = "duda";
  p5->valorSublista = nullptr;

  p6 = new Lista;
  p6->sublista = false;
  p6->valorString = "oioi";
  p6->valorSublista = nullptr;

  p5->proximo= p6;

  p4->proximo= p5;


  p7 = new Lista;
  p7->sublista = true;
  p7->valorString = "";
  p7->valorSublista = p4;


  p7->proximo = nullptr;

  p3->proximo = p7;

  p2->proximo = p3;

  p1->proximo = p2;

  p0->proximo = p1;

  return p0;
}
