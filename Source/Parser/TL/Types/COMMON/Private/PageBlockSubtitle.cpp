#include "../Public/PageBlockSubtitle.h"


//begin namespace block
namespace COMMON
{

PageBlockSubtitle::PageBlockSubtitle()
{
	this->_ConstructorID = -1879401953;
}

PageBlockSubtitle::PageBlockSubtitle(TLBaseObject*  text)
{
	this->_ConstructorID = -1879401953;
	this->text = text;
}
void PageBlockSubtitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockSubtitle::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockSubtitle::~PageBlockSubtitle()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
