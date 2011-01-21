/* -*-c++-*- OpenRTI - Copyright (C) 2009-2011 Mathias Froehlich
 *
 *
 * This file is part of OpenRTI.
 *
 * OpenRTI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * OpenRTI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenRTI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * This file is autogenerated by messagegen.py. Do not edit!
 *
 */

#ifndef OpenRTI_AbstractMessageDispatcher_h
#define OpenRTI_AbstractMessageDispatcher_h

namespace OpenRTI {

class AbstractMessage;

class CreateFederationExecutionRequestMessage;
class CreateFederationExecutionResponseMessage;
class DestroyFederationExecutionRequestMessage;
class DestroyFederationExecutionResponseMessage;
class EnumerateFederationExecutionsRequestMessage;
class EnumerateFederationExecutionsResponseMessage;
class InsertFederationExecutionMessage;
class EraseFederationExecutionMessage;
class JoinFederationExecutionRequestMessage;
class JoinFederationExecutionResponseMessage;
class ResignFederationExecutionRequestMessage;
class ResignFederationExecutionResponseMessage;
class JoinFederateNotifyMessage;
class ResignFederateNotifyMessage;
class ChangeDefaultResignActionMessage;
class RegisterFederationSynchronizationPointMessage;
class RegisterFederationSynchronizationPointResponseMessage;
class AnnounceSynchronizationPointMessage;
class SynchronizationPointAchievedMessage;
class FederationSynchronizedMessage;
class EnableTimeRegulationRequestMessage;
class EnableTimeRegulationResponseMessage;
class DisableTimeRegulationRequestMessage;
class CommitLowerBoundTimeStampMessage;
class TimeConstrainedEnabledMessage;
class TimeRegulationEnabledMessage;
class TimeAdvanceGrantedMessage;
class ChangeInteractionClassPublicationMessage;
class ChangeObjectClassPublicationMessage;
class ChangeInteractionClassSubscriptionMessage;
class ChangeObjectClassSubscriptionMessage;
class RegistrationForObjectClassMessage;
class TurnInteractionsOnMessage;
class InteractionMessage;
class TimeStampedInteractionMessage;
class ObjectInstanceHandlesRequestMessage;
class ObjectInstanceHandlesResponseMessage;
class ReleaseMultipleObjectInstanceNameHandlePairsMessage;
class ReserveObjectInstanceNameRequestMessage;
class ReserveObjectInstanceNameResponseMessage;
class ReserveMultipleObjectInstanceNameRequestMessage;
class ReserveMultipleObjectInstanceNameResponseMessage;
class InsertObjectInstanceMessage;
class DeleteObjectInstanceMessage;
class TimeStampedDeleteObjectInstanceMessage;
class LocalDeleteObjectInstanceMessage;
class AttributeUpdateMessage;
class TimeStampedAttributeUpdateMessage;
class RequestAttributeUpdateMessage;
class RequestClassAttributeUpdateMessage;

class OPENRTI_LOCAL AbstractMessageDispatcher {
public:
  virtual ~AbstractMessageDispatcher() {}

  virtual void accept(CreateFederationExecutionRequestMessage&) = 0;
  virtual void accept(CreateFederationExecutionResponseMessage&) = 0;
  virtual void accept(DestroyFederationExecutionRequestMessage&) = 0;
  virtual void accept(DestroyFederationExecutionResponseMessage&) = 0;
  virtual void accept(EnumerateFederationExecutionsRequestMessage&) = 0;
  virtual void accept(EnumerateFederationExecutionsResponseMessage&) = 0;
  virtual void accept(InsertFederationExecutionMessage&) = 0;
  virtual void accept(EraseFederationExecutionMessage&) = 0;
  virtual void accept(JoinFederationExecutionRequestMessage&) = 0;
  virtual void accept(JoinFederationExecutionResponseMessage&) = 0;
  virtual void accept(ResignFederationExecutionRequestMessage&) = 0;
  virtual void accept(ResignFederationExecutionResponseMessage&) = 0;
  virtual void accept(JoinFederateNotifyMessage&) = 0;
  virtual void accept(ResignFederateNotifyMessage&) = 0;
  virtual void accept(ChangeDefaultResignActionMessage&) = 0;
  virtual void accept(RegisterFederationSynchronizationPointMessage&) = 0;
  virtual void accept(RegisterFederationSynchronizationPointResponseMessage&) = 0;
  virtual void accept(AnnounceSynchronizationPointMessage&) = 0;
  virtual void accept(SynchronizationPointAchievedMessage&) = 0;
  virtual void accept(FederationSynchronizedMessage&) = 0;
  virtual void accept(EnableTimeRegulationRequestMessage&) = 0;
  virtual void accept(EnableTimeRegulationResponseMessage&) = 0;
  virtual void accept(DisableTimeRegulationRequestMessage&) = 0;
  virtual void accept(CommitLowerBoundTimeStampMessage&) = 0;
  virtual void accept(TimeConstrainedEnabledMessage&) = 0;
  virtual void accept(TimeRegulationEnabledMessage&) = 0;
  virtual void accept(TimeAdvanceGrantedMessage&) = 0;
  virtual void accept(ChangeInteractionClassPublicationMessage&) = 0;
  virtual void accept(ChangeObjectClassPublicationMessage&) = 0;
  virtual void accept(ChangeInteractionClassSubscriptionMessage&) = 0;
  virtual void accept(ChangeObjectClassSubscriptionMessage&) = 0;
  virtual void accept(RegistrationForObjectClassMessage&) = 0;
  virtual void accept(TurnInteractionsOnMessage&) = 0;
  virtual void accept(InteractionMessage&) = 0;
  virtual void accept(TimeStampedInteractionMessage&) = 0;
  virtual void accept(ObjectInstanceHandlesRequestMessage&) = 0;
  virtual void accept(ObjectInstanceHandlesResponseMessage&) = 0;
  virtual void accept(ReleaseMultipleObjectInstanceNameHandlePairsMessage&) = 0;
  virtual void accept(ReserveObjectInstanceNameRequestMessage&) = 0;
  virtual void accept(ReserveObjectInstanceNameResponseMessage&) = 0;
  virtual void accept(ReserveMultipleObjectInstanceNameRequestMessage&) = 0;
  virtual void accept(ReserveMultipleObjectInstanceNameResponseMessage&) = 0;
  virtual void accept(InsertObjectInstanceMessage&) = 0;
  virtual void accept(DeleteObjectInstanceMessage&) = 0;
  virtual void accept(TimeStampedDeleteObjectInstanceMessage&) = 0;
  virtual void accept(LocalDeleteObjectInstanceMessage&) = 0;
  virtual void accept(AttributeUpdateMessage&) = 0;
  virtual void accept(TimeStampedAttributeUpdateMessage&) = 0;
  virtual void accept(RequestAttributeUpdateMessage&) = 0;
  virtual void accept(RequestClassAttributeUpdateMessage&) = 0;
};

template<typename T>
class OPENRTI_LOCAL FunctorMessageDispatcher : public AbstractMessageDispatcher {
public:
  FunctorMessageDispatcher(const T& t) : _t(t) {}
  virtual ~FunctorMessageDispatcher() {}

  virtual void accept(CreateFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(CreateFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(DestroyFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(DestroyFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(EnumerateFederationExecutionsRequestMessage& message) { _t(message); }
  virtual void accept(EnumerateFederationExecutionsResponseMessage& message) { _t(message); }
  virtual void accept(InsertFederationExecutionMessage& message) { _t(message); }
  virtual void accept(EraseFederationExecutionMessage& message) { _t(message); }
  virtual void accept(JoinFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(JoinFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(ResignFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(ResignFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(JoinFederateNotifyMessage& message) { _t(message); }
  virtual void accept(ResignFederateNotifyMessage& message) { _t(message); }
  virtual void accept(ChangeDefaultResignActionMessage& message) { _t(message); }
  virtual void accept(RegisterFederationSynchronizationPointMessage& message) { _t(message); }
  virtual void accept(RegisterFederationSynchronizationPointResponseMessage& message) { _t(message); }
  virtual void accept(AnnounceSynchronizationPointMessage& message) { _t(message); }
  virtual void accept(SynchronizationPointAchievedMessage& message) { _t(message); }
  virtual void accept(FederationSynchronizedMessage& message) { _t(message); }
  virtual void accept(EnableTimeRegulationRequestMessage& message) { _t(message); }
  virtual void accept(EnableTimeRegulationResponseMessage& message) { _t(message); }
  virtual void accept(DisableTimeRegulationRequestMessage& message) { _t(message); }
  virtual void accept(CommitLowerBoundTimeStampMessage& message) { _t(message); }
  virtual void accept(TimeConstrainedEnabledMessage& message) { _t(message); }
  virtual void accept(TimeRegulationEnabledMessage& message) { _t(message); }
  virtual void accept(TimeAdvanceGrantedMessage& message) { _t(message); }
  virtual void accept(ChangeInteractionClassPublicationMessage& message) { _t(message); }
  virtual void accept(ChangeObjectClassPublicationMessage& message) { _t(message); }
  virtual void accept(ChangeInteractionClassSubscriptionMessage& message) { _t(message); }
  virtual void accept(ChangeObjectClassSubscriptionMessage& message) { _t(message); }
  virtual void accept(RegistrationForObjectClassMessage& message) { _t(message); }
  virtual void accept(TurnInteractionsOnMessage& message) { _t(message); }
  virtual void accept(InteractionMessage& message) { _t(message); }
  virtual void accept(TimeStampedInteractionMessage& message) { _t(message); }
  virtual void accept(ObjectInstanceHandlesRequestMessage& message) { _t(message); }
  virtual void accept(ObjectInstanceHandlesResponseMessage& message) { _t(message); }
  virtual void accept(ReleaseMultipleObjectInstanceNameHandlePairsMessage& message) { _t(message); }
  virtual void accept(ReserveObjectInstanceNameRequestMessage& message) { _t(message); }
  virtual void accept(ReserveObjectInstanceNameResponseMessage& message) { _t(message); }
  virtual void accept(ReserveMultipleObjectInstanceNameRequestMessage& message) { _t(message); }
  virtual void accept(ReserveMultipleObjectInstanceNameResponseMessage& message) { _t(message); }
  virtual void accept(InsertObjectInstanceMessage& message) { _t(message); }
  virtual void accept(DeleteObjectInstanceMessage& message) { _t(message); }
  virtual void accept(TimeStampedDeleteObjectInstanceMessage& message) { _t(message); }
  virtual void accept(LocalDeleteObjectInstanceMessage& message) { _t(message); }
  virtual void accept(AttributeUpdateMessage& message) { _t(message); }
  virtual void accept(TimeStampedAttributeUpdateMessage& message) { _t(message); }
  virtual void accept(RequestAttributeUpdateMessage& message) { _t(message); }
  virtual void accept(RequestClassAttributeUpdateMessage& message) { _t(message); }
private:
  const T& _t;
};

class OPENRTI_LOCAL ConstAbstractMessageDispatcher {
public:
  virtual ~ConstAbstractMessageDispatcher() {}

  virtual void accept(const CreateFederationExecutionRequestMessage&) = 0;
  virtual void accept(const CreateFederationExecutionResponseMessage&) = 0;
  virtual void accept(const DestroyFederationExecutionRequestMessage&) = 0;
  virtual void accept(const DestroyFederationExecutionResponseMessage&) = 0;
  virtual void accept(const EnumerateFederationExecutionsRequestMessage&) = 0;
  virtual void accept(const EnumerateFederationExecutionsResponseMessage&) = 0;
  virtual void accept(const InsertFederationExecutionMessage&) = 0;
  virtual void accept(const EraseFederationExecutionMessage&) = 0;
  virtual void accept(const JoinFederationExecutionRequestMessage&) = 0;
  virtual void accept(const JoinFederationExecutionResponseMessage&) = 0;
  virtual void accept(const ResignFederationExecutionRequestMessage&) = 0;
  virtual void accept(const ResignFederationExecutionResponseMessage&) = 0;
  virtual void accept(const JoinFederateNotifyMessage&) = 0;
  virtual void accept(const ResignFederateNotifyMessage&) = 0;
  virtual void accept(const ChangeDefaultResignActionMessage&) = 0;
  virtual void accept(const RegisterFederationSynchronizationPointMessage&) = 0;
  virtual void accept(const RegisterFederationSynchronizationPointResponseMessage&) = 0;
  virtual void accept(const AnnounceSynchronizationPointMessage&) = 0;
  virtual void accept(const SynchronizationPointAchievedMessage&) = 0;
  virtual void accept(const FederationSynchronizedMessage&) = 0;
  virtual void accept(const EnableTimeRegulationRequestMessage&) = 0;
  virtual void accept(const EnableTimeRegulationResponseMessage&) = 0;
  virtual void accept(const DisableTimeRegulationRequestMessage&) = 0;
  virtual void accept(const CommitLowerBoundTimeStampMessage&) = 0;
  virtual void accept(const TimeConstrainedEnabledMessage&) = 0;
  virtual void accept(const TimeRegulationEnabledMessage&) = 0;
  virtual void accept(const TimeAdvanceGrantedMessage&) = 0;
  virtual void accept(const ChangeInteractionClassPublicationMessage&) = 0;
  virtual void accept(const ChangeObjectClassPublicationMessage&) = 0;
  virtual void accept(const ChangeInteractionClassSubscriptionMessage&) = 0;
  virtual void accept(const ChangeObjectClassSubscriptionMessage&) = 0;
  virtual void accept(const RegistrationForObjectClassMessage&) = 0;
  virtual void accept(const TurnInteractionsOnMessage&) = 0;
  virtual void accept(const InteractionMessage&) = 0;
  virtual void accept(const TimeStampedInteractionMessage&) = 0;
  virtual void accept(const ObjectInstanceHandlesRequestMessage&) = 0;
  virtual void accept(const ObjectInstanceHandlesResponseMessage&) = 0;
  virtual void accept(const ReleaseMultipleObjectInstanceNameHandlePairsMessage&) = 0;
  virtual void accept(const ReserveObjectInstanceNameRequestMessage&) = 0;
  virtual void accept(const ReserveObjectInstanceNameResponseMessage&) = 0;
  virtual void accept(const ReserveMultipleObjectInstanceNameRequestMessage&) = 0;
  virtual void accept(const ReserveMultipleObjectInstanceNameResponseMessage&) = 0;
  virtual void accept(const InsertObjectInstanceMessage&) = 0;
  virtual void accept(const DeleteObjectInstanceMessage&) = 0;
  virtual void accept(const TimeStampedDeleteObjectInstanceMessage&) = 0;
  virtual void accept(const LocalDeleteObjectInstanceMessage&) = 0;
  virtual void accept(const AttributeUpdateMessage&) = 0;
  virtual void accept(const TimeStampedAttributeUpdateMessage&) = 0;
  virtual void accept(const RequestAttributeUpdateMessage&) = 0;
  virtual void accept(const RequestClassAttributeUpdateMessage&) = 0;
};

template<typename T>
class OPENRTI_LOCAL FunctorConstMessageDispatcher : public ConstAbstractMessageDispatcher {
public:
  FunctorConstMessageDispatcher(const T& t) : _t(t) {}
  virtual ~FunctorConstMessageDispatcher() {}

  virtual void accept(const CreateFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(const CreateFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(const DestroyFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(const DestroyFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(const EnumerateFederationExecutionsRequestMessage& message) { _t(message); }
  virtual void accept(const EnumerateFederationExecutionsResponseMessage& message) { _t(message); }
  virtual void accept(const InsertFederationExecutionMessage& message) { _t(message); }
  virtual void accept(const EraseFederationExecutionMessage& message) { _t(message); }
  virtual void accept(const JoinFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(const JoinFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(const ResignFederationExecutionRequestMessage& message) { _t(message); }
  virtual void accept(const ResignFederationExecutionResponseMessage& message) { _t(message); }
  virtual void accept(const JoinFederateNotifyMessage& message) { _t(message); }
  virtual void accept(const ResignFederateNotifyMessage& message) { _t(message); }
  virtual void accept(const ChangeDefaultResignActionMessage& message) { _t(message); }
  virtual void accept(const RegisterFederationSynchronizationPointMessage& message) { _t(message); }
  virtual void accept(const RegisterFederationSynchronizationPointResponseMessage& message) { _t(message); }
  virtual void accept(const AnnounceSynchronizationPointMessage& message) { _t(message); }
  virtual void accept(const SynchronizationPointAchievedMessage& message) { _t(message); }
  virtual void accept(const FederationSynchronizedMessage& message) { _t(message); }
  virtual void accept(const EnableTimeRegulationRequestMessage& message) { _t(message); }
  virtual void accept(const EnableTimeRegulationResponseMessage& message) { _t(message); }
  virtual void accept(const DisableTimeRegulationRequestMessage& message) { _t(message); }
  virtual void accept(const CommitLowerBoundTimeStampMessage& message) { _t(message); }
  virtual void accept(const TimeConstrainedEnabledMessage& message) { _t(message); }
  virtual void accept(const TimeRegulationEnabledMessage& message) { _t(message); }
  virtual void accept(const TimeAdvanceGrantedMessage& message) { _t(message); }
  virtual void accept(const ChangeInteractionClassPublicationMessage& message) { _t(message); }
  virtual void accept(const ChangeObjectClassPublicationMessage& message) { _t(message); }
  virtual void accept(const ChangeInteractionClassSubscriptionMessage& message) { _t(message); }
  virtual void accept(const ChangeObjectClassSubscriptionMessage& message) { _t(message); }
  virtual void accept(const RegistrationForObjectClassMessage& message) { _t(message); }
  virtual void accept(const TurnInteractionsOnMessage& message) { _t(message); }
  virtual void accept(const InteractionMessage& message) { _t(message); }
  virtual void accept(const TimeStampedInteractionMessage& message) { _t(message); }
  virtual void accept(const ObjectInstanceHandlesRequestMessage& message) { _t(message); }
  virtual void accept(const ObjectInstanceHandlesResponseMessage& message) { _t(message); }
  virtual void accept(const ReleaseMultipleObjectInstanceNameHandlePairsMessage& message) { _t(message); }
  virtual void accept(const ReserveObjectInstanceNameRequestMessage& message) { _t(message); }
  virtual void accept(const ReserveObjectInstanceNameResponseMessage& message) { _t(message); }
  virtual void accept(const ReserveMultipleObjectInstanceNameRequestMessage& message) { _t(message); }
  virtual void accept(const ReserveMultipleObjectInstanceNameResponseMessage& message) { _t(message); }
  virtual void accept(const InsertObjectInstanceMessage& message) { _t(message); }
  virtual void accept(const DeleteObjectInstanceMessage& message) { _t(message); }
  virtual void accept(const TimeStampedDeleteObjectInstanceMessage& message) { _t(message); }
  virtual void accept(const LocalDeleteObjectInstanceMessage& message) { _t(message); }
  virtual void accept(const AttributeUpdateMessage& message) { _t(message); }
  virtual void accept(const TimeStampedAttributeUpdateMessage& message) { _t(message); }
  virtual void accept(const RequestAttributeUpdateMessage& message) { _t(message); }
  virtual void accept(const RequestClassAttributeUpdateMessage& message) { _t(message); }
private:
  const T& _t;
};

} // namespace OpenRTI

#endif
