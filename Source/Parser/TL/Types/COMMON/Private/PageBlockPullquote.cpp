#include "../Public/PageBlockPullquote.h"


//begin namespace block
namespace COMMON
{

PageBlockPullquote::PageBlockPullquote()
{
	this->_ConstructorID = 1329878739;
}

PageBlockPullquote::PageBlockPullquote(TLBaseObject*  text, TLBaseObject*  caption)
{
	this->_ConstructorID = 1329878739;
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
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	caption = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockPullquote::~PageBlockPullquote()
{
	if(this->text)
	{
		delete this->text;
	}
	if(this->caption)
	{
		delete this->caption;
	}
}
}//end namespace block
