#include "../Public/PageBlockSubheader.h"


//begin namespace block
namespace COMMON
{

PageBlockSubheader::PageBlockSubheader()
{
	this->_ConstructorID = -508154895;
}

PageBlockSubheader::PageBlockSubheader(PRIVATE::RichText* text)
{
	this->_ConstructorID = -508154895;
	this->text = text;
}
void PageBlockSubheader::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockSubheader::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockSubheader::~PageBlockSubheader()
{

}
}//end namespace block
