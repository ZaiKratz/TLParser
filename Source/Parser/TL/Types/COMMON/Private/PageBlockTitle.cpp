#include "../Public/PageBlockTitle.h"


//begin namespace block
namespace COMMON
{

PageBlockTitle::PageBlockTitle()
{
	this->_ConstructorID = 1890305021;
}

PageBlockTitle::PageBlockTitle(TLBaseObject*  text)
{
	this->_ConstructorID = 1890305021;
	this->text = text;
}
void PageBlockTitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockTitle::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockTitle::~PageBlockTitle()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
