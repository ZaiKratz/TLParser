#include "../Public/PageBlockBlockquote.h"


//begin namespace block
namespace COMMON
{

PageBlockBlockquote::PageBlockBlockquote()
{
	this->_ConstructorID = 641563686;
}

PageBlockBlockquote::PageBlockBlockquote(PRIVATE::RichText*  text, PRIVATE::RichText*  caption)
{
	this->_ConstructorID = 641563686;
	this->text = text;
	this->caption = caption;
}
void PageBlockBlockquote::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
	this->caption->OnSend(Writer);
}


void PageBlockBlockquote::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText* >(Reader.TGReadObject());
	caption = reinterpret_cast<PRIVATE::RichText* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockBlockquote::~PageBlockBlockquote()
{

}
}//end namespace block
