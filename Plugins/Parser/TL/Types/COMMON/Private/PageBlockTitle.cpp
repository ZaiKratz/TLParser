#include "../Public/PageBlockTitle.h"


//begin namespace block
namespace COMMON
{

PageBlockTitle::PageBlockTitle()
{
	this->_ConstructorID = -37508240;
}

PageBlockTitle::PageBlockTitle(PRIVATE::RichText* text)
{
	this->_ConstructorID = -37508240;
	this->text = text;
}
void PageBlockTitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockTitle::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockTitle::~PageBlockTitle()
{

}
}//end namespace block
