#include "../Public/TextStrike.h"


//begin namespace block
namespace COMMON
{

TextStrike::TextStrike()
{
	this->_ConstructorID = -1782843237;
}

TextStrike::TextStrike(PRIVATE::RichText* text)
{
	this->_ConstructorID = -1782843237;
	this->text = text;
}
void TextStrike::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextStrike::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
TextStrike::~TextStrike()
{

}
}//end namespace block
