#include "../Public/DocumentAttributeAnimated.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeAnimated::DocumentAttributeAnimated()
{
	this->_ConstructorID = 965326097;
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
}
DocumentAttributeAnimated::~DocumentAttributeAnimated()
{

}
}//end namespace block
