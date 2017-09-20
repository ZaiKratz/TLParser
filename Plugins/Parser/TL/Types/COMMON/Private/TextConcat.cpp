#include "../Public/TextConcat.h"


//begin namespace block
namespace COMMON
{

TextConcat::TextConcat()
{
	this->_ConstructorID = -681549186;
}

TextConcat::TextConcat(TArray<PRIVATE::RichText*> texts)
{
	this->_ConstructorID = -681549186;
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
	int32 Len12278 = Reader.ReadInt();
	for(int32 i = 0; i < Len12278; i++)
	{
	auto X = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
	texts.Add(X);
	}
}
TextConcat::~TextConcat()
{

}
}//end namespace block
