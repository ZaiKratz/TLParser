#include "../Public/TextPlain.h"


//begin namespace block
namespace COMMON
{

TextPlain::TextPlain()
{
	this->_ConstructorID = 1950782688;
}

TextPlain::TextPlain(FString text)
{
	this->_ConstructorID = 1950782688;
	this->text = text;
}
void TextPlain::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void TextPlain::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
TextPlain::~TextPlain()
{

}
}//end namespace block
