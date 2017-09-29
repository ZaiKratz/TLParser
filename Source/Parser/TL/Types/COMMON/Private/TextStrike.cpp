#include "../Public/TextStrike.h"


//begin namespace block
namespace COMMON
{

TextStrike::TextStrike()
{
	this->_ConstructorID = -1678197867;
}

TextStrike::TextStrike(PRIVATE::RichText*  text)
{
	this->_ConstructorID = -1678197867;
	this->text = text;
}
void TextStrike::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextStrike::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText* >(Reader.TGReadObject());
	this->_Responded = true;
}
TextStrike::~TextStrike()
{

}
}//end namespace block
