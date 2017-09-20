#include "../Public/PageBlockPullquote.h"


//begin namespace block
namespace COMMON
{

PageBlockPullquote::PageBlockPullquote()
{
	this->_ConstructorID = -749321137;
}

PageBlockPullquote::PageBlockPullquote(PRIVATE::RichText* text, PRIVATE::RichText* caption)
{
	this->_ConstructorID = -749321137;
	this->text = text;
	this->caption = caption;
}
void PageBlockPullquote::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
	this->caption->OnSend(Writer);
}


void PageBlockPullquote::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
	caption = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockPullquote::~PageBlockPullquote()
{

}
}//end namespace block
