#include "../Public/PrivacyValueAllowAll.h"


//begin namespace block
namespace COMMON
{

PrivacyValueAllowAll::PrivacyValueAllowAll()
{
	this->_ConstructorID = 1698855810;
}
void PrivacyValueAllowAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyValueAllowAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PrivacyValueAllowAll::~PrivacyValueAllowAll()
{
}
}//end namespace block
