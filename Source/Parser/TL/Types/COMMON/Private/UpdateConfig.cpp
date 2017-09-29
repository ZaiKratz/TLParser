#include "../Public/UpdateConfig.h"


//begin namespace block
namespace COMMON
{

UpdateConfig::UpdateConfig()
{
	this->_ConstructorID = -1574314746;
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
	this->_Responded = true;
}
UpdateConfig::~UpdateConfig()
{

}
}//end namespace block
