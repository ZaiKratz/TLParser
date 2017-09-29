#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PhoneCallProtocol : public TLBaseObject
{
public:
	PhoneCallProtocol();
	PhoneCallProtocol(bool udp_p2p, bool udp_reflector, int32 min_layer, int32 max_layer);

	~PhoneCallProtocol();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetUdpP2P() const
	{
		 return this->udp_p2p;
	}

	bool GetUdpReflector() const
	{
		 return this->udp_reflector;
	}

	int32 GetMinLayer() const
	{
		 return this->min_layer;
	}

	int32 GetMaxLayer() const
	{
		 return this->max_layer;
	}

private:
	bool udp_p2p;
	 bool udp_reflector;
	 int32 min_layer;
	 int32 max_layer;
};
} //end namespace block
