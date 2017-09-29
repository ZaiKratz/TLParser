#include "../Public/TextFixed.h"


//begin namespace block
namespace COMMON
{

TextFixed::TextFixed()
{
	this->_ConstructorID = 1816074681;
}

TextFixed::TextFixed(PRIVATE::RichText*  text)
{
	this->_ConstructorID = 1816074681;
	this->text = text;
}
void TextFixed::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextFixed::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText* >(Reader.TGReadObject());
	this->_Responded = true;
}
TextFixed::~TextFixed()
{

}
}//end namespace block
