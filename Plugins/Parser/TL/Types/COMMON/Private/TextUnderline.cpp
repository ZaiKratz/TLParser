#include "../Public/TextUnderline.h"


//begin namespace block
namespace COMMON
{

TextUnderline::TextUnderline()
{
	this->_ConstructorID = -1004394815;
}

TextUnderline::TextUnderline(PRIVATE::RichText* text)
{
	this->_ConstructorID = -1004394815;
	this->text = text;
}
void TextUnderline::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextUnderline::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
TextUnderline::~TextUnderline()
{

}
}//end namespace block
