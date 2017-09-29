#include "../Public/UserProfilePhotoEmpty.h"


//begin namespace block
namespace COMMON
{

UserProfilePhotoEmpty::UserProfilePhotoEmpty()
{
	this->_ConstructorID = 1326562017;
}
void UserProfilePhotoEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UserProfilePhotoEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UserProfilePhotoEmpty::~UserProfilePhotoEmpty()
{

}
}//end namespace block
