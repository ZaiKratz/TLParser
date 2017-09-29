#include "../Public/TextUnderline.h"


//begin namespace block
namespace COMMON
{

TextUnderline::TextUnderline()
{
	this->_ConstructorID = -1054465340;
}

TextUnderline::TextUnderline(PRIVATE::RichText*  text)
{
	this->_ConstructorID = -1054465340;
	this->text = text;
}
void TextUnderline::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextUnderline::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText* >(Reader.TGReadObject());
	this->_Responded = true;
}
TextUnderline::~TextUnderline()
{

}
}//end namespace block
