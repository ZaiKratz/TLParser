#include "../Public/TextBold.h"


//begin namespace block
namespace COMMON
{

TextBold::TextBold()
{
	this->_ConstructorID = -995416985;
}

TextBold::TextBold(PRIVATE::RichText* text)
{
	this->_ConstructorID = -995416985;
	this->text = text;
}
void TextBold::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void TextBold::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
TextBold::~TextBold()
{

}
}//end namespace block
