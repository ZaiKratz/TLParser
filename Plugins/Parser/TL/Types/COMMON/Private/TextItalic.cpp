#include "../Public/TextItalic.h"


//begin namespace block
namespace COMMON
{

TextItalic::TextItalic()
{
	this->_ConstructorID = -1666903335;
}

TextItalic::TextItalic(PRIVATE::RichText* text)
{
	this->_ConstructorID = -1666903335;
	this->text = text;
}
void TextItalic::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextItalic::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
TextItalic::~TextItalic()
{

}
}//end namespace block
