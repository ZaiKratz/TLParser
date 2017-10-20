#include "../Public/PageBlockBlockquote.h"


//begin namespace block
namespace COMMON
{

PageBlockBlockquote::PageBlockBlockquote()
{
	this->_ConstructorID = 641563686;
}

PageBlockBlockquote::PageBlockBlockquote(TLBaseObject*  text, TLBaseObject*  caption)
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
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	caption = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockBlockquote::~PageBlockBlockquote()
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
