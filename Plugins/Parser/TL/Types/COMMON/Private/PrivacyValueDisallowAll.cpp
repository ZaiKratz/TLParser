#include "../Public/PrivacyValueDisallowAll.h"


//begin namespace block
namespace COMMON
{

PrivacyValueDisallowAll::PrivacyValueDisallowAll()
{
	this->_ConstructorID = 1676112779;
}
void PrivacyValueDisallowAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyValueDisallowAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
PrivacyValueDisallowAll::~PrivacyValueDisallowAll()
{

}
}//end namespace block
