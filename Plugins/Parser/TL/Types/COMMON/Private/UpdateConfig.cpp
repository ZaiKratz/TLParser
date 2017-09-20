#include "../Public/UpdateConfig.h"


//begin namespace block
namespace COMMON
{

UpdateConfig::UpdateConfig()
{
	this->_ConstructorID = 115157410;
}
void UpdateConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateConfig::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UpdateConfig::~UpdateConfig()
{

}
}//end namespace block
