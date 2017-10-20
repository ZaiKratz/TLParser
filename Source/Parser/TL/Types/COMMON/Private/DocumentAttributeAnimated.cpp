#include "../Public/DocumentAttributeAnimated.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeAnimated::DocumentAttributeAnimated()
{
	this->_ConstructorID = 297109817;
}
void DocumentAttributeAnimated::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void DocumentAttributeAnimated::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
DocumentAttributeAnimated::~DocumentAttributeAnimated()
{
}
}//end namespace block
