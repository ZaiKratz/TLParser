#include "../Public/TextConcat.h"


//begin namespace block
namespace COMMON
{

TextConcat::TextConcat()
{
	this->_ConstructorID = 2120376535;
}

TextConcat::TextConcat(TArray<PRIVATE::RichText*>  texts)
{
	this->_ConstructorID = 2120376535;
	this->texts = texts;
}
void TextConcat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->texts.Num());
	for(auto X : this->texts)
	{
	X->OnSend(Writer);
	}
}


void TextConcat::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len10111 = Reader.ReadInt();
	for(int32 i = 0; i < Len10111; i++)
	{
	auto X = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
	texts.Add(X);
	}
	this->_Responded = true;
}
TextConcat::~TextConcat()
{

}
}//end namespace block
