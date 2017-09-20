#include "../Public/PageBlockSubtitle.h"


//begin namespace block
namespace COMMON
{

PageBlockSubtitle::PageBlockSubtitle()
{
	this->_ConstructorID = 530250383;
}

PageBlockSubtitle::PageBlockSubtitle(PRIVATE::RichText* text)
{
	this->_ConstructorID = 530250383;
	this->text = text;
}
void PageBlockSubtitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockSubtitle::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockSubtitle::~PageBlockSubtitle()
{

}
}//end namespace block
