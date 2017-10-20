#include "../Public/PageBlockFooter.h"


//begin namespace block
namespace COMMON
{

PageBlockFooter::PageBlockFooter()
{
	this->_ConstructorID = 1216809369;
}

PageBlockFooter::PageBlockFooter(TLBaseObject*  text)
{
	this->_ConstructorID = 1216809369;
	this->text = text;
}
void PageBlockFooter::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->text->OnSend(Writer);
}


void PageBlockFooter::OnResponce(BinaryReader& Reader)
{
	text = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockFooter::~PageBlockFooter()
{
	if(this->text)
	{
		delete this->text;
	}
}
}//end namespace block
