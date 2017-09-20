#include "../Public/TextPlain.h"


//begin namespace block
namespace COMMON
{

TextPlain::TextPlain()
{
	this->_ConstructorID = -527153548;
}

TextPlain::TextPlain(FString text)
{
	this->_ConstructorID = -527153548;
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
}
TextPlain::~TextPlain()
{

}
}//end namespace block
