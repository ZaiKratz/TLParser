#include "../Public/TextFixed.h"


//begin namespace block
namespace COMMON
{

TextFixed::TextFixed()
{
	this->_ConstructorID = 1816074681;
}

TextFixed::TextFixed(TLBaseObject*  text)
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
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
TextFixed::~TextFixed()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
