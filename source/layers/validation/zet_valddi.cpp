/*
 * ***THIS FILE IS GENERATED. ***
 * See valddi.cpp.mako for modifications
 *
 * Copyright (C) 2019-2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zet_valddi.cpp
 *
 */
#include "ze_validation_layer.h"

namespace validation_layer
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetModuleGetDebugInfo
    __zedlllocal ze_result_t ZE_APICALL
    zetModuleGetDebugInfo(
        zet_module_handle_t hModule,                    ///< [in] handle of the module
        zet_module_debug_info_format_t format,          ///< [in] debug info format requested
        size_t* pSize,                                  ///< [in,out] size of debug info in bytes
        uint8_t* pDebugInfo                             ///< [in,out][optional] byte pointer to debug info
        )
    {
        auto pfnGetDebugInfo = context.zetDdiTable.Module.pfnGetDebugInfo;

        if( nullptr == pfnGetDebugInfo )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetModuleGetDebugInfoPrologue( hModule, format, pSize, pDebugInfo );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetModuleGetDebugInfoPrologue( hModule, format, pSize, pDebugInfo );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetDebugInfo( hModule, format, pSize, pDebugInfo );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetModuleGetDebugInfoEpilogue( hModule, format, pSize, pDebugInfo ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDeviceGetDebugProperties
    __zedlllocal ze_result_t ZE_APICALL
    zetDeviceGetDebugProperties(
        zet_device_handle_t hDevice,                    ///< [in] device handle
        zet_device_debug_properties_t* pDebugProperties ///< [in,out] query result for debug properties
        )
    {
        auto pfnGetDebugProperties = context.zetDdiTable.Device.pfnGetDebugProperties;

        if( nullptr == pfnGetDebugProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDeviceGetDebugPropertiesPrologue( hDevice, pDebugProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDeviceGetDebugPropertiesPrologue( hDevice, pDebugProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetDebugProperties( hDevice, pDebugProperties );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDeviceGetDebugPropertiesEpilogue( hDevice, pDebugProperties ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugAttach
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugAttach(
        zet_device_handle_t hDevice,                    ///< [in] device handle
        const zet_debug_config_t* config,               ///< [in] the debug configuration
        zet_debug_session_handle_t* phDebug             ///< [out] debug session handle
        )
    {
        auto pfnAttach = context.zetDdiTable.Debug.pfnAttach;

        if( nullptr == pfnAttach )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugAttachPrologue( hDevice, config, phDebug );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugAttachPrologue( hDevice, config, phDebug );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnAttach( hDevice, config, phDebug );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugAttachEpilogue( hDevice, config, phDebug ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugDetach
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugDetach(
        zet_debug_session_handle_t hDebug               ///< [in][release] debug session handle
        )
    {
        auto pfnDetach = context.zetDdiTable.Debug.pfnDetach;

        if( nullptr == pfnDetach )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugDetachPrologue( hDebug );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugDetachPrologue( hDebug );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDetach( hDebug );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugDetachEpilogue( hDebug ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugReadEvent
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugReadEvent(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t timeout,                               ///< [in] if non-zero, then indicates the maximum time (in milliseconds) to
                                                        ///< yield before returning ::ZE_RESULT_SUCCESS or ::ZE_RESULT_NOT_READY;
                                                        ///< if zero, then immediately returns the status of the event;
                                                        ///< if `UINT64_MAX`, then function will not return until complete or
                                                        ///< device is lost.
                                                        ///< Due to external dependencies, timeout may be rounded to the closest
                                                        ///< value allowed by the accuracy of those dependencies.
        zet_debug_event_t* event                        ///< [in,out] a pointer to a ::zet_debug_event_t.
        )
    {
        auto pfnReadEvent = context.zetDdiTable.Debug.pfnReadEvent;

        if( nullptr == pfnReadEvent )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugReadEventPrologue( hDebug, timeout, event );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugReadEventPrologue( hDebug, timeout, event );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnReadEvent( hDebug, timeout, event );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugReadEventEpilogue( hDebug, timeout, event ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugAcknowledgeEvent
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugAcknowledgeEvent(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        const zet_debug_event_t* event                  ///< [in] a pointer to a ::zet_debug_event_t.
        )
    {
        auto pfnAcknowledgeEvent = context.zetDdiTable.Debug.pfnAcknowledgeEvent;

        if( nullptr == pfnAcknowledgeEvent )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugAcknowledgeEventPrologue( hDebug, event );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugAcknowledgeEventPrologue( hDebug, event );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnAcknowledgeEvent( hDebug, event );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugAcknowledgeEventEpilogue( hDebug, event ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugInterrupt
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugInterrupt(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        ze_device_thread_t thread                       ///< [in] the thread to interrupt
        )
    {
        auto pfnInterrupt = context.zetDdiTable.Debug.pfnInterrupt;

        if( nullptr == pfnInterrupt )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugInterruptPrologue( hDebug, thread );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugInterruptPrologue( hDebug, thread );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnInterrupt( hDebug, thread );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugInterruptEpilogue( hDebug, thread ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugResume
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugResume(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        ze_device_thread_t thread                       ///< [in] the thread to resume
        )
    {
        auto pfnResume = context.zetDdiTable.Debug.pfnResume;

        if( nullptr == pfnResume )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugResumePrologue( hDebug, thread );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugResumePrologue( hDebug, thread );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnResume( hDebug, thread );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugResumeEpilogue( hDebug, thread ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugReadMemory
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugReadMemory(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        ze_device_thread_t thread,                      ///< [in] the thread identifier.
        const zet_debug_memory_space_desc_t* desc,      ///< [in] memory space descriptor
        size_t size,                                    ///< [in] the number of bytes to read
        void* buffer                                    ///< [in,out] a buffer to hold a copy of the memory
        )
    {
        auto pfnReadMemory = context.zetDdiTable.Debug.pfnReadMemory;

        if( nullptr == pfnReadMemory )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugReadMemoryPrologue( hDebug, thread, desc, size, buffer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugReadMemoryPrologue( hDebug, thread, desc, size, buffer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnReadMemory( hDebug, thread, desc, size, buffer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugReadMemoryEpilogue( hDebug, thread, desc, size, buffer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugWriteMemory
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugWriteMemory(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        ze_device_thread_t thread,                      ///< [in] the thread identifier.
        const zet_debug_memory_space_desc_t* desc,      ///< [in] memory space descriptor
        size_t size,                                    ///< [in] the number of bytes to write
        const void* buffer                              ///< [in] a buffer holding the pattern to write
        )
    {
        auto pfnWriteMemory = context.zetDdiTable.Debug.pfnWriteMemory;

        if( nullptr == pfnWriteMemory )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugWriteMemoryPrologue( hDebug, thread, desc, size, buffer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugWriteMemoryPrologue( hDebug, thread, desc, size, buffer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnWriteMemory( hDebug, thread, desc, size, buffer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugWriteMemoryEpilogue( hDebug, thread, desc, size, buffer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugGetRegisterSetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugGetRegisterSetProperties(
        zet_device_handle_t hDevice,                    ///< [in] device handle
        uint32_t* pCount,                               ///< [in,out] pointer to the number of register set properties.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of register set properties available.
                                                        ///< if count is greater than the number of register set properties
                                                        ///< available, then the driver shall update the value with the correct
                                                        ///< number of registry set properties available.
        zet_debug_regset_properties_t* pRegisterSetProperties   ///< [in,out][optional][range(0, *pCount)] array of query results for
                                                        ///< register set properties.
                                                        ///< if count is less than the number of register set properties available,
                                                        ///< then driver shall only retrieve that number of register set properties.
        )
    {
        auto pfnGetRegisterSetProperties = context.zetDdiTable.Debug.pfnGetRegisterSetProperties;

        if( nullptr == pfnGetRegisterSetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugGetRegisterSetPropertiesPrologue( hDevice, pCount, pRegisterSetProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugGetRegisterSetPropertiesPrologue( hDevice, pCount, pRegisterSetProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetRegisterSetProperties( hDevice, pCount, pRegisterSetProperties );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugGetRegisterSetPropertiesEpilogue( hDevice, pCount, pRegisterSetProperties ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugGetThreadRegisterSetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugGetThreadRegisterSetProperties(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        ze_device_thread_t thread,                      ///< [in] the thread identifier specifying a single stopped thread
        uint32_t* pCount,                               ///< [in,out] pointer to the number of register set properties.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of register set properties available.
                                                        ///< if count is greater than the number of register set properties
                                                        ///< available, then the driver shall update the value with the correct
                                                        ///< number of registry set properties available.
        zet_debug_regset_properties_t* pRegisterSetProperties   ///< [in,out][optional][range(0, *pCount)] array of query results for
                                                        ///< register set properties.
                                                        ///< if count is less than the number of register set properties available,
                                                        ///< then driver shall only retrieve that number of register set properties.
        )
    {
        auto pfnGetThreadRegisterSetProperties = context.zetDdiTable.Debug.pfnGetThreadRegisterSetProperties;

        if( nullptr == pfnGetThreadRegisterSetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugGetThreadRegisterSetPropertiesPrologue( hDebug, thread, pCount, pRegisterSetProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugGetThreadRegisterSetPropertiesPrologue( hDebug, thread, pCount, pRegisterSetProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetThreadRegisterSetProperties( hDebug, thread, pCount, pRegisterSetProperties );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugGetThreadRegisterSetPropertiesEpilogue( hDebug, thread, pCount, pRegisterSetProperties ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugReadRegisters
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugReadRegisters(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        ze_device_thread_t thread,                      ///< [in] the thread identifier
        uint32_t type,                                  ///< [in] register set type
        uint32_t start,                                 ///< [in] the starting offset into the register state area; must be less
                                                        ///< than the `count` member of ::zet_debug_regset_properties_t for the
                                                        ///< type
        uint32_t count,                                 ///< [in] the number of registers to read; start+count must be less than or
                                                        ///< equal to the `count` member of ::zet_debug_register_group_properties_t
                                                        ///< for the type
        void* pRegisterValues                           ///< [in,out][optional][range(0, count)] buffer of register values
        )
    {
        auto pfnReadRegisters = context.zetDdiTable.Debug.pfnReadRegisters;

        if( nullptr == pfnReadRegisters )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugReadRegistersPrologue( hDebug, thread, type, start, count, pRegisterValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugReadRegistersPrologue( hDebug, thread, type, start, count, pRegisterValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnReadRegisters( hDebug, thread, type, start, count, pRegisterValues );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugReadRegistersEpilogue( hDebug, thread, type, start, count, pRegisterValues ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugWriteRegisters
    __zedlllocal ze_result_t ZE_APICALL
    zetDebugWriteRegisters(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        ze_device_thread_t thread,                      ///< [in] the thread identifier
        uint32_t type,                                  ///< [in] register set type
        uint32_t start,                                 ///< [in] the starting offset into the register state area; must be less
                                                        ///< than the `count` member of ::zet_debug_regset_properties_t for the
                                                        ///< type
        uint32_t count,                                 ///< [in] the number of registers to write; start+count must be less than
                                                        ///< or equal to the `count` member of
                                                        ///< ::zet_debug_register_group_properties_t for the type
        void* pRegisterValues                           ///< [in,out][optional][range(0, count)] buffer of register values
        )
    {
        auto pfnWriteRegisters = context.zetDdiTable.Debug.pfnWriteRegisters;

        if( nullptr == pfnWriteRegisters )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugWriteRegistersPrologue( hDebug, thread, type, start, count, pRegisterValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDebugWriteRegistersPrologue( hDebug, thread, type, start, count, pRegisterValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnWriteRegisters( hDebug, thread, type, start, count, pRegisterValues );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDebugWriteRegistersEpilogue( hDebug, thread, type, start, count, pRegisterValues ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupGet
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupGet(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of metric groups.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metric groups available.
                                                        ///< if count is greater than the number of metric groups available, then
                                                        ///< the driver shall update the value with the correct number of metric
                                                        ///< groups available.
        zet_metric_group_handle_t* phMetricGroups       ///< [in,out][optional][range(0, *pCount)] array of handle of metric groups.
                                                        ///< if count is less than the number of metric groups available, then
                                                        ///< driver shall only retrieve that number of metric groups.
        )
    {
        auto pfnGet = context.zetDdiTable.MetricGroup.pfnGet;

        if( nullptr == pfnGet )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetPrologue( hDevice, pCount, phMetricGroups );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupGetPrologue( hDevice, pCount, phMetricGroups );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGet( hDevice, pCount, phMetricGroups );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetEpilogue( hDevice, pCount, phMetricGroups ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            for (size_t i = 0; ( nullptr != phMetricGroups) && (i < *pCount); ++i){
                if (phMetricGroups[i]){
                    context.handleLifetime->addHandle( phMetricGroups[i] );
                    context.handleLifetime->addDependent( hDevice, phMetricGroups[i] );
                }
            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupGetProperties(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        zet_metric_group_properties_t* pProperties      ///< [in,out] metric group properties
        )
    {
        auto pfnGetProperties = context.zetDdiTable.MetricGroup.pfnGetProperties;

        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetPropertiesPrologue( hMetricGroup, pProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupGetPropertiesPrologue( hMetricGroup, pProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetProperties( hMetricGroup, pProperties );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetPropertiesEpilogue( hMetricGroup, pProperties ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupCalculateMetricValues
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupCalculateMetricValues(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        zet_metric_group_calculation_type_t type,       ///< [in] calculation type to be applied on raw data
        size_t rawDataSize,                             ///< [in] size in bytes of raw data buffer
        const uint8_t* pRawData,                        ///< [in][range(0, rawDataSize)] buffer of raw data to calculate
        uint32_t* pMetricValueCount,                    ///< [in,out] pointer to number of metric values calculated.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metric values to be calculated.
                                                        ///< if count is greater than the number available in the raw data buffer,
                                                        ///< then the driver shall update the value with the actual number of
                                                        ///< metric values to be calculated.
        zet_typed_value_t* pMetricValues                ///< [in,out][optional][range(0, *pMetricValueCount)] buffer of calculated metrics.
                                                        ///< if count is less than the number available in the raw data buffer,
                                                        ///< then driver shall only calculate that number of metric values.
        )
    {
        auto pfnCalculateMetricValues = context.zetDdiTable.MetricGroup.pfnCalculateMetricValues;

        if( nullptr == pfnCalculateMetricValues )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCalculateMetricValuesPrologue( hMetricGroup, type, rawDataSize, pRawData, pMetricValueCount, pMetricValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupCalculateMetricValuesPrologue( hMetricGroup, type, rawDataSize, pRawData, pMetricValueCount, pMetricValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCalculateMetricValues( hMetricGroup, type, rawDataSize, pRawData, pMetricValueCount, pMetricValues );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCalculateMetricValuesEpilogue( hMetricGroup, type, rawDataSize, pRawData, pMetricValueCount, pMetricValues ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGet
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGet(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        uint32_t* pCount,                               ///< [in,out] pointer to the number of metrics.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metrics available.
                                                        ///< if count is greater than the number of metrics available, then the
                                                        ///< driver shall update the value with the correct number of metrics available.
        zet_metric_handle_t* phMetrics                  ///< [in,out][optional][range(0, *pCount)] array of handle of metrics.
                                                        ///< if count is less than the number of metrics available, then driver
                                                        ///< shall only retrieve that number of metrics.
        )
    {
        auto pfnGet = context.zetDdiTable.Metric.pfnGet;

        if( nullptr == pfnGet )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGetPrologue( hMetricGroup, pCount, phMetrics );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGetPrologue( hMetricGroup, pCount, phMetrics );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGet( hMetricGroup, pCount, phMetrics );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGetEpilogue( hMetricGroup, pCount, phMetrics ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            for (size_t i = 0; ( nullptr != phMetrics) && (i < *pCount); ++i){
                if (phMetrics[i]){
                    context.handleLifetime->addHandle( phMetrics[i] );
                    context.handleLifetime->addDependent( hMetricGroup, phMetrics[i] );
                }
            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGetProperties(
        zet_metric_handle_t hMetric,                    ///< [in] handle of the metric
        zet_metric_properties_t* pProperties            ///< [in,out] metric properties
        )
    {
        auto pfnGetProperties = context.zetDdiTable.Metric.pfnGetProperties;

        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGetPropertiesPrologue( hMetric, pProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGetPropertiesPrologue( hMetric, pProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetProperties( hMetric, pProperties );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGetPropertiesEpilogue( hMetric, pProperties ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetContextActivateMetricGroups
    __zedlllocal ze_result_t ZE_APICALL
    zetContextActivateMetricGroups(
        zet_context_handle_t hContext,                  ///< [in] handle of the context object
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t count,                                 ///< [in] metric group count to activate; must be 0 if `nullptr ==
                                                        ///< phMetricGroups`
        zet_metric_group_handle_t* phMetricGroups       ///< [in][optional][range(0, count)] handles of the metric groups to activate.
                                                        ///< nullptr deactivates all previously used metric groups.
                                                        ///< all metrics groups must come from a different domains.
                                                        ///< metric query and metric stream must use activated metric groups.
        )
    {
        auto pfnActivateMetricGroups = context.zetDdiTable.Context.pfnActivateMetricGroups;

        if( nullptr == pfnActivateMetricGroups )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetContextActivateMetricGroupsPrologue( hContext, hDevice, count, phMetricGroups );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetContextActivateMetricGroupsPrologue( hContext, hDevice, count, phMetricGroups );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnActivateMetricGroups( hContext, hDevice, count, phMetricGroups );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetContextActivateMetricGroupsEpilogue( hContext, hDevice, count, phMetricGroups ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricStreamerOpen
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricStreamerOpen(
        zet_context_handle_t hContext,                  ///< [in] handle of the context object
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        zet_metric_streamer_desc_t* desc,               ///< [in,out] metric streamer descriptor
        ze_event_handle_t hNotificationEvent,           ///< [in][optional] event used for report availability notification
        zet_metric_streamer_handle_t* phMetricStreamer  ///< [out] handle of metric streamer
        )
    {
        auto pfnOpen = context.zetDdiTable.MetricStreamer.pfnOpen;

        if( nullptr == pfnOpen )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricStreamerOpenPrologue( hContext, hDevice, hMetricGroup, desc, hNotificationEvent, phMetricStreamer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricStreamerOpenPrologue( hContext, hDevice, hMetricGroup, desc, hNotificationEvent, phMetricStreamer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnOpen( hContext, hDevice, hMetricGroup, desc, hNotificationEvent, phMetricStreamer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricStreamerOpenEpilogue( hContext, hDevice, hMetricGroup, desc, hNotificationEvent, phMetricStreamer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricStreamerMarker
    __zedlllocal ze_result_t ZE_APICALL
    zetCommandListAppendMetricStreamerMarker(
        zet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        zet_metric_streamer_handle_t hMetricStreamer,   ///< [in] handle of the metric streamer
        uint32_t value                                  ///< [in] streamer marker value
        )
    {
        auto pfnAppendMetricStreamerMarker = context.zetDdiTable.CommandList.pfnAppendMetricStreamerMarker;

        if( nullptr == pfnAppendMetricStreamerMarker )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricStreamerMarkerPrologue( hCommandList, hMetricStreamer, value );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetCommandListAppendMetricStreamerMarkerPrologue( hCommandList, hMetricStreamer, value );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnAppendMetricStreamerMarker( hCommandList, hMetricStreamer, value );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricStreamerMarkerEpilogue( hCommandList, hMetricStreamer, value ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricStreamerClose
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricStreamerClose(
        zet_metric_streamer_handle_t hMetricStreamer    ///< [in][release] handle of the metric streamer
        )
    {
        auto pfnClose = context.zetDdiTable.MetricStreamer.pfnClose;

        if( nullptr == pfnClose )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricStreamerClosePrologue( hMetricStreamer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricStreamerClosePrologue( hMetricStreamer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnClose( hMetricStreamer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricStreamerCloseEpilogue( hMetricStreamer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricStreamerReadData
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricStreamerReadData(
        zet_metric_streamer_handle_t hMetricStreamer,   ///< [in] handle of the metric streamer
        uint32_t maxReportCount,                        ///< [in] the maximum number of reports the application wants to receive.
                                                        ///< if `UINT32_MAX`, then function will retrieve all reports available
        size_t* pRawDataSize,                           ///< [in,out] pointer to size in bytes of raw data requested to read.
                                                        ///< if size is zero, then the driver will update the value with the total
                                                        ///< size in bytes needed for all reports available.
                                                        ///< if size is non-zero, then driver will only retrieve the number of
                                                        ///< reports that fit into the buffer.
                                                        ///< if size is larger than size needed for all reports, then driver will
                                                        ///< update the value with the actual size needed.
        uint8_t* pRawData                               ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing streamer
                                                        ///< reports in raw format
        )
    {
        auto pfnReadData = context.zetDdiTable.MetricStreamer.pfnReadData;

        if( nullptr == pfnReadData )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricStreamerReadDataPrologue( hMetricStreamer, maxReportCount, pRawDataSize, pRawData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricStreamerReadDataPrologue( hMetricStreamer, maxReportCount, pRawDataSize, pRawData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnReadData( hMetricStreamer, maxReportCount, pRawDataSize, pRawData );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricStreamerReadDataEpilogue( hMetricStreamer, maxReportCount, pRawDataSize, pRawData ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryPoolCreate
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricQueryPoolCreate(
        zet_context_handle_t hContext,                  ///< [in] handle of the context object
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        zet_metric_group_handle_t hMetricGroup,         ///< [in] metric group associated with the query object.
        const zet_metric_query_pool_desc_t* desc,       ///< [in] metric query pool descriptor
        zet_metric_query_pool_handle_t* phMetricQueryPool   ///< [out] handle of metric query pool
        )
    {
        auto pfnCreate = context.zetDdiTable.MetricQueryPool.pfnCreate;

        if( nullptr == pfnCreate )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryPoolCreatePrologue( hContext, hDevice, hMetricGroup, desc, phMetricQueryPool );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricQueryPoolCreatePrologue( hContext, hDevice, hMetricGroup, desc, phMetricQueryPool );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreate( hContext, hDevice, hMetricGroup, desc, phMetricQueryPool );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryPoolCreateEpilogue( hContext, hDevice, hMetricGroup, desc, phMetricQueryPool ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            if (phMetricQueryPool){
                context.handleLifetime->addHandle( *phMetricQueryPool );
                context.handleLifetime->addDependent( hContext, *phMetricQueryPool );

            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryPoolDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricQueryPoolDestroy(
        zet_metric_query_pool_handle_t hMetricQueryPool ///< [in][release] handle of the metric query pool
        )
    {
        auto pfnDestroy = context.zetDdiTable.MetricQueryPool.pfnDestroy;

        if( nullptr == pfnDestroy )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryPoolDestroyPrologue( hMetricQueryPool );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricQueryPoolDestroyPrologue( hMetricQueryPool );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDestroy( hMetricQueryPool );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryPoolDestroyEpilogue( hMetricQueryPool ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryCreate
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricQueryCreate(
        zet_metric_query_pool_handle_t hMetricQueryPool,///< [in] handle of the metric query pool
        uint32_t index,                                 ///< [in] index of the query within the pool
        zet_metric_query_handle_t* phMetricQuery        ///< [out] handle of metric query
        )
    {
        auto pfnCreate = context.zetDdiTable.MetricQuery.pfnCreate;

        if( nullptr == pfnCreate )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryCreatePrologue( hMetricQueryPool, index, phMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricQueryCreatePrologue( hMetricQueryPool, index, phMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreate( hMetricQueryPool, index, phMetricQuery );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryCreateEpilogue( hMetricQueryPool, index, phMetricQuery ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            if (phMetricQuery){
                context.handleLifetime->addHandle( *phMetricQuery );
                context.handleLifetime->addDependent( hMetricQueryPool, *phMetricQuery );

            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricQueryDestroy(
        zet_metric_query_handle_t hMetricQuery          ///< [in][release] handle of metric query
        )
    {
        auto pfnDestroy = context.zetDdiTable.MetricQuery.pfnDestroy;

        if( nullptr == pfnDestroy )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryDestroyPrologue( hMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricQueryDestroyPrologue( hMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDestroy( hMetricQuery );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryDestroyEpilogue( hMetricQuery ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryReset
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricQueryReset(
        zet_metric_query_handle_t hMetricQuery          ///< [in] handle of metric query
        )
    {
        auto pfnReset = context.zetDdiTable.MetricQuery.pfnReset;

        if( nullptr == pfnReset )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryResetPrologue( hMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricQueryResetPrologue( hMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnReset( hMetricQuery );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryResetEpilogue( hMetricQuery ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricQueryBegin
    __zedlllocal ze_result_t ZE_APICALL
    zetCommandListAppendMetricQueryBegin(
        zet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        zet_metric_query_handle_t hMetricQuery          ///< [in] handle of the metric query
        )
    {
        auto pfnAppendMetricQueryBegin = context.zetDdiTable.CommandList.pfnAppendMetricQueryBegin;

        if( nullptr == pfnAppendMetricQueryBegin )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricQueryBeginPrologue( hCommandList, hMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetCommandListAppendMetricQueryBeginPrologue( hCommandList, hMetricQuery );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnAppendMetricQueryBegin( hCommandList, hMetricQuery );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricQueryBeginEpilogue( hCommandList, hMetricQuery ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricQueryEnd
    __zedlllocal ze_result_t ZE_APICALL
    zetCommandListAppendMetricQueryEnd(
        zet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        zet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in] must be zero
        ze_event_handle_t* phWaitEvents                 ///< [in][mbz] must be nullptr
        )
    {
        auto pfnAppendMetricQueryEnd = context.zetDdiTable.CommandList.pfnAppendMetricQueryEnd;

        if( nullptr == pfnAppendMetricQueryEnd )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricQueryEndPrologue( hCommandList, hMetricQuery, hSignalEvent, numWaitEvents, phWaitEvents );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetCommandListAppendMetricQueryEndPrologue( hCommandList, hMetricQuery, hSignalEvent, numWaitEvents, phWaitEvents );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnAppendMetricQueryEnd( hCommandList, hMetricQuery, hSignalEvent, numWaitEvents, phWaitEvents );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricQueryEndEpilogue( hCommandList, hMetricQuery, hSignalEvent, numWaitEvents, phWaitEvents ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricMemoryBarrier
    __zedlllocal ze_result_t ZE_APICALL
    zetCommandListAppendMetricMemoryBarrier(
        zet_command_list_handle_t hCommandList          ///< [in] handle of the command list
        )
    {
        auto pfnAppendMetricMemoryBarrier = context.zetDdiTable.CommandList.pfnAppendMetricMemoryBarrier;

        if( nullptr == pfnAppendMetricMemoryBarrier )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricMemoryBarrierPrologue( hCommandList );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetCommandListAppendMetricMemoryBarrierPrologue( hCommandList );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnAppendMetricMemoryBarrier( hCommandList );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetCommandListAppendMetricMemoryBarrierEpilogue( hCommandList ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryGetData
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricQueryGetData(
        zet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
        size_t* pRawDataSize,                           ///< [in,out] pointer to size in bytes of raw data requested to read.
                                                        ///< if size is zero, then the driver will update the value with the total
                                                        ///< size in bytes needed for all reports available.
                                                        ///< if size is non-zero, then driver will only retrieve the number of
                                                        ///< reports that fit into the buffer.
                                                        ///< if size is larger than size needed for all reports, then driver will
                                                        ///< update the value with the actual size needed.
        uint8_t* pRawData                               ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing query
                                                        ///< reports in raw format
        )
    {
        auto pfnGetData = context.zetDdiTable.MetricQuery.pfnGetData;

        if( nullptr == pfnGetData )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryGetDataPrologue( hMetricQuery, pRawDataSize, pRawData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricQueryGetDataPrologue( hMetricQuery, pRawDataSize, pRawData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetData( hMetricQuery, pRawDataSize, pRawData );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricQueryGetDataEpilogue( hMetricQuery, pRawDataSize, pRawData ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetKernelGetProfileInfo
    __zedlllocal ze_result_t ZE_APICALL
    zetKernelGetProfileInfo(
        zet_kernel_handle_t hKernel,                    ///< [in] handle to kernel
        zet_profile_properties_t* pProfileProperties    ///< [out] pointer to profile properties
        )
    {
        auto pfnGetProfileInfo = context.zetDdiTable.Kernel.pfnGetProfileInfo;

        if( nullptr == pfnGetProfileInfo )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetKernelGetProfileInfoPrologue( hKernel, pProfileProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetKernelGetProfileInfoPrologue( hKernel, pProfileProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetProfileInfo( hKernel, pProfileProperties );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetKernelGetProfileInfoEpilogue( hKernel, pProfileProperties ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerExpCreate
    __zedlllocal ze_result_t ZE_APICALL
    zetTracerExpCreate(
        zet_context_handle_t hContext,                  ///< [in] handle of the context object
        const zet_tracer_exp_desc_t* desc,              ///< [in] pointer to tracer descriptor
        zet_tracer_exp_handle_t* phTracer               ///< [out] pointer to handle of tracer object created
        )
    {
        auto pfnCreate = context.zetDdiTable.TracerExp.pfnCreate;

        if( nullptr == pfnCreate )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpCreatePrologue( hContext, desc, phTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetTracerExpCreatePrologue( hContext, desc, phTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreate( hContext, desc, phTracer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpCreateEpilogue( hContext, desc, phTracer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            if (phTracer){
                context.handleLifetime->addHandle( *phTracer );
                context.handleLifetime->addDependent( hContext, *phTracer );

            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerExpDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zetTracerExpDestroy(
        zet_tracer_exp_handle_t hTracer                 ///< [in][release] handle of tracer object to destroy
        )
    {
        auto pfnDestroy = context.zetDdiTable.TracerExp.pfnDestroy;

        if( nullptr == pfnDestroy )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpDestroyPrologue( hTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetTracerExpDestroyPrologue( hTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDestroy( hTracer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpDestroyEpilogue( hTracer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerExpSetPrologues
    __zedlllocal ze_result_t ZE_APICALL
    zetTracerExpSetPrologues(
        zet_tracer_exp_handle_t hTracer,                ///< [in] handle of the tracer
        zet_core_callbacks_t* pCoreCbs                  ///< [in] pointer to table of 'core' callback function pointers
        )
    {
        auto pfnSetPrologues = context.zetDdiTable.TracerExp.pfnSetPrologues;

        if( nullptr == pfnSetPrologues )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpSetProloguesPrologue( hTracer, pCoreCbs );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetTracerExpSetProloguesPrologue( hTracer, pCoreCbs );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnSetPrologues( hTracer, pCoreCbs );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpSetProloguesEpilogue( hTracer, pCoreCbs ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerExpSetEpilogues
    __zedlllocal ze_result_t ZE_APICALL
    zetTracerExpSetEpilogues(
        zet_tracer_exp_handle_t hTracer,                ///< [in] handle of the tracer
        zet_core_callbacks_t* pCoreCbs                  ///< [in] pointer to table of 'core' callback function pointers
        )
    {
        auto pfnSetEpilogues = context.zetDdiTable.TracerExp.pfnSetEpilogues;

        if( nullptr == pfnSetEpilogues )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpSetEpiloguesPrologue( hTracer, pCoreCbs );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetTracerExpSetEpiloguesPrologue( hTracer, pCoreCbs );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnSetEpilogues( hTracer, pCoreCbs );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpSetEpiloguesEpilogue( hTracer, pCoreCbs ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerExpSetEnabled
    __zedlllocal ze_result_t ZE_APICALL
    zetTracerExpSetEnabled(
        zet_tracer_exp_handle_t hTracer,                ///< [in] handle of the tracer
        ze_bool_t enable                                ///< [in] enable the tracer if true; disable if false
        )
    {
        auto pfnSetEnabled = context.zetDdiTable.TracerExp.pfnSetEnabled;

        if( nullptr == pfnSetEnabled )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpSetEnabledPrologue( hTracer, enable );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetTracerExpSetEnabledPrologue( hTracer, enable );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnSetEnabled( hTracer, enable );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetTracerExpSetEnabledEpilogue( hTracer, enable ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDeviceGetConcurrentMetricGroupsExp
    __zedlllocal ze_result_t ZE_APICALL
    zetDeviceGetConcurrentMetricGroupsExp(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t metricGroupCount,                      ///< [in] metric group count
        zet_metric_group_handle_t * phMetricGroups,     ///< [in,out] metrics groups to be re-arranged to be sets of concurrent
                                                        ///< groups
        uint32_t * pMetricGroupsCountPerConcurrentGroup,///< [in,out][optional][*pConcurrentGroupCount] count of metric groups per
                                                        ///< concurrent group.
        uint32_t * pConcurrentGroupCount                ///< [out] number of concurrent groups.
                                                        ///< The value of this parameter could be used to determine the number of
                                                        ///< replays necessary.
        )
    {
        auto pfnGetConcurrentMetricGroupsExp = context.zetDdiTable.DeviceExp.pfnGetConcurrentMetricGroupsExp;

        if( nullptr == pfnGetConcurrentMetricGroupsExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDeviceGetConcurrentMetricGroupsExpPrologue( hDevice, metricGroupCount, phMetricGroups, pMetricGroupsCountPerConcurrentGroup, pConcurrentGroupCount );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDeviceGetConcurrentMetricGroupsExpPrologue( hDevice, metricGroupCount, phMetricGroups, pMetricGroupsCountPerConcurrentGroup, pConcurrentGroupCount );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetConcurrentMetricGroupsExp( hDevice, metricGroupCount, phMetricGroups, pMetricGroupsCountPerConcurrentGroup, pConcurrentGroupCount );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDeviceGetConcurrentMetricGroupsExpEpilogue( hDevice, metricGroupCount, phMetricGroups, pMetricGroupsCountPerConcurrentGroup, pConcurrentGroupCount ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerCreateExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricTracerCreateExp(
        zet_context_handle_t hContext,                  ///< [in] handle of the context object
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t metricGroupCount,                      ///< [in] metric group count
        zet_metric_group_handle_t* phMetricGroups,      ///< [in][range(0, metricGroupCount )] handles of the metric groups to
                                                        ///< trace
        zet_metric_tracer_exp_desc_t* desc,             ///< [in,out] metric tracer descriptor
        ze_event_handle_t hNotificationEvent,           ///< [in][optional] event used for report availability notification. Note:
                                                        ///< If buffer is not drained when the event it flagged, there is a risk of
                                                        ///< HW event buffer being overrun
        zet_metric_tracer_exp_handle_t* phMetricTracer  ///< [out] handle of the metric tracer
        )
    {
        auto pfnCreateExp = context.zetDdiTable.MetricTracerExp.pfnCreateExp;

        if( nullptr == pfnCreateExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerCreateExpPrologue( hContext, hDevice, metricGroupCount, phMetricGroups, desc, hNotificationEvent, phMetricTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricTracerCreateExpPrologue( hContext, hDevice, metricGroupCount, phMetricGroups, desc, hNotificationEvent, phMetricTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreateExp( hContext, hDevice, metricGroupCount, phMetricGroups, desc, hNotificationEvent, phMetricTracer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerCreateExpEpilogue( hContext, hDevice, metricGroupCount, phMetricGroups, desc, hNotificationEvent, phMetricTracer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            if (phMetricTracer){
                context.handleLifetime->addHandle( *phMetricTracer );
                context.handleLifetime->addDependent( hContext, *phMetricTracer );

            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerDestroyExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricTracerDestroyExp(
        zet_metric_tracer_exp_handle_t hMetricTracer    ///< [in] handle of the metric tracer
        )
    {
        auto pfnDestroyExp = context.zetDdiTable.MetricTracerExp.pfnDestroyExp;

        if( nullptr == pfnDestroyExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerDestroyExpPrologue( hMetricTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricTracerDestroyExpPrologue( hMetricTracer );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDestroyExp( hMetricTracer );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerDestroyExpEpilogue( hMetricTracer ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerEnableExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricTracerEnableExp(
        zet_metric_tracer_exp_handle_t hMetricTracer,   ///< [in] handle of the metric tracer
        ze_bool_t synchronous                           ///< [in] request synchronous behavior. Confirmation of successful
                                                        ///< asynchronous operation is done by calling ::zetMetricTracerReadDataExp()
                                                        ///< and checking the return status: ::ZE_RESULT_NOT_READY will be returned
                                                        ///< when the tracer is inactive. ::ZE_RESULT_SUCCESS will be returned 
                                                        ///< when the tracer is active.
        )
    {
        auto pfnEnableExp = context.zetDdiTable.MetricTracerExp.pfnEnableExp;

        if( nullptr == pfnEnableExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerEnableExpPrologue( hMetricTracer, synchronous );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricTracerEnableExpPrologue( hMetricTracer, synchronous );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnEnableExp( hMetricTracer, synchronous );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerEnableExpEpilogue( hMetricTracer, synchronous ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerDisableExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricTracerDisableExp(
        zet_metric_tracer_exp_handle_t hMetricTracer,   ///< [in] handle of the metric tracer
        ze_bool_t synchronous                           ///< [in] request synchronous behavior. Confirmation of successful
                                                        ///< asynchronous operation is done by calling ::zetMetricTracerReadDataExp()
                                                        ///< and checking the return status: ::ZE_RESULT_SUCCESS will be returned
                                                        ///< when the tracer is active or when it is inactive but still has data. 
                                                        ///< ::ZE_RESULT_NOT_READY will be returned when the tracer is inactive and
                                                        ///< has no more data to be retrieved.
        )
    {
        auto pfnDisableExp = context.zetDdiTable.MetricTracerExp.pfnDisableExp;

        if( nullptr == pfnDisableExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerDisableExpPrologue( hMetricTracer, synchronous );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricTracerDisableExpPrologue( hMetricTracer, synchronous );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDisableExp( hMetricTracer, synchronous );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerDisableExpEpilogue( hMetricTracer, synchronous ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerReadDataExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricTracerReadDataExp(
        zet_metric_tracer_exp_handle_t hMetricTracer,   ///< [in] handle of the metric tracer
        size_t* pRawDataSize,                           ///< [in,out] pointer to size in bytes of raw data requested to read.
                                                        ///< if size is zero, then the driver will update the value with the total
                                                        ///< size in bytes needed for all data available.
                                                        ///< if size is non-zero, then driver will only retrieve that amount of
                                                        ///< data. 
                                                        ///< if size is larger than size needed for all data, then driver will
                                                        ///< update the value with the actual size needed.
        uint8_t* pRawData                               ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing tracer
                                                        ///< data in raw format
        )
    {
        auto pfnReadDataExp = context.zetDdiTable.MetricTracerExp.pfnReadDataExp;

        if( nullptr == pfnReadDataExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerReadDataExpPrologue( hMetricTracer, pRawDataSize, pRawData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricTracerReadDataExpPrologue( hMetricTracer, pRawDataSize, pRawData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnReadDataExp( hMetricTracer, pRawDataSize, pRawData );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerReadDataExpEpilogue( hMetricTracer, pRawDataSize, pRawData ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricDecoderCreateExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricDecoderCreateExp(
        zet_metric_tracer_exp_handle_t hMetricTracer,   ///< [in] handle of the metric tracer
        zet_metric_decoder_exp_handle_t* phMetricDecoder///< [out] handle of the metric decoder object
        )
    {
        auto pfnCreateExp = context.zetDdiTable.MetricDecoderExp.pfnCreateExp;

        if( nullptr == pfnCreateExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDecoderCreateExpPrologue( hMetricTracer, phMetricDecoder );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricDecoderCreateExpPrologue( hMetricTracer, phMetricDecoder );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreateExp( hMetricTracer, phMetricDecoder );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDecoderCreateExpEpilogue( hMetricTracer, phMetricDecoder ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            if (phMetricDecoder){
                context.handleLifetime->addHandle( *phMetricDecoder );
                context.handleLifetime->addDependent( hMetricTracer, *phMetricDecoder );

            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricDecoderDestroyExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricDecoderDestroyExp(
        zet_metric_decoder_exp_handle_t phMetricDecoder ///< [in] handle of the metric decoder object
        )
    {
        auto pfnDestroyExp = context.zetDdiTable.MetricDecoderExp.pfnDestroyExp;

        if( nullptr == pfnDestroyExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDecoderDestroyExpPrologue( phMetricDecoder );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricDecoderDestroyExpPrologue( phMetricDecoder );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDestroyExp( phMetricDecoder );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDecoderDestroyExpEpilogue( phMetricDecoder ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricDecoderGetDecodableMetricsExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricDecoderGetDecodableMetricsExp(
        zet_metric_decoder_exp_handle_t hMetricDecoder, ///< [in] handle of the metric decoder object
        uint32_t* pCount,                               ///< [in,out] pointer to number of decodable metric in the hMetricDecoder
                                                        ///< handle. If count is zero, then the driver shall 
                                                        ///< update the value with the total number of decodable metrics available
                                                        ///< in the decoder. if count is greater than zero 
                                                        ///< but less than the total number of decodable metrics available in the
                                                        ///< decoder, then only that number will be returned. 
                                                        ///< if count is greater than the number of decodable metrics available in
                                                        ///< the decoder, then the driver shall update the 
                                                        ///< value with the actual number of decodable metrics available. 
        zet_metric_handle_t* phMetrics                  ///< [in,out] [range(0, *pCount)] array of handles of decodable metrics in
                                                        ///< the hMetricDecoder handle provided.
        )
    {
        auto pfnGetDecodableMetricsExp = context.zetDdiTable.MetricDecoderExp.pfnGetDecodableMetricsExp;

        if( nullptr == pfnGetDecodableMetricsExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDecoderGetDecodableMetricsExpPrologue( hMetricDecoder, pCount, phMetrics );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricDecoderGetDecodableMetricsExpPrologue( hMetricDecoder, pCount, phMetrics );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetDecodableMetricsExp( hMetricDecoder, pCount, phMetrics );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDecoderGetDecodableMetricsExpEpilogue( hMetricDecoder, pCount, phMetrics ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            for (size_t i = 0; ( nullptr != phMetrics) && (i < *pCount); ++i){
                if (phMetrics[i]){
                    context.handleLifetime->addHandle( phMetrics[i] );
                    context.handleLifetime->addDependent( hMetricDecoder, phMetrics[i] );
                }
            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerDecodeExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricTracerDecodeExp(
        zet_metric_decoder_exp_handle_t phMetricDecoder,///< [in] handle of the metric decoder object
        size_t* pRawDataSize,                           ///< [in,out] size in bytes of raw data buffer. If pMetricEntriesCount is
                                                        ///< greater than zero but less than total number of 
                                                        ///< decodable metrics available in the raw data buffer, then driver shall
                                                        ///< update this value with actual number of raw 
                                                        ///< data bytes processed.
        uint8_t* pRawData,                              ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing tracer
                                                        ///< data in raw format
        uint32_t metricsCount,                          ///< [in] number of decodable metrics in the tracer for which the
                                                        ///< hMetricDecoder handle was provided. See 
                                                        ///< ::zetMetricDecoderGetDecodableMetricsExp(). If metricCount is greater
                                                        ///< than zero but less than the number decodable 
                                                        ///< metrics available in the raw data buffer, then driver shall only
                                                        ///< decode those.
        zet_metric_handle_t* phMetrics,                 ///< [in] [range(0, metricsCount)] array of handles of decodable metrics in
                                                        ///< the decoder for which the hMetricDecoder handle was 
                                                        ///< provided. Metrics handles are expected to be for decodable metrics,
                                                        ///< see ::zetMetricDecoderGetDecodableMetrics() 
        uint32_t* pSetCount,                            ///< [in,out] pointer to number of metric sets. If count is zero, then the
                                                        ///< driver shall update the value with the total
                                                        ///< number of metric sets to be decoded. If count is greater than the
                                                        ///< number available in the raw data buffer, then the
                                                        ///< driver shall update the value with the actual number of metric sets to
                                                        ///< be decoded. There is a 1:1 relation between
                                                        ///< the number of sets and sub-devices returned in the decoded entries.
        uint32_t* pMetricEntriesCountPerSet,            ///< [in,out][optional][range(0, *pSetCount)] buffer of metric entries
                                                        ///< counts per metric set, one value per set.
        uint32_t* pMetricEntriesCount,                  ///< [in,out]  pointer to the total number of metric entries decoded, for
                                                        ///< all metric sets. If count is zero, then the
                                                        ///< driver shall update the value with the total number of metric entries
                                                        ///< to be decoded. If count is greater than zero
                                                        ///< but less than the total number of metric entries available in the raw
                                                        ///< data, then user provided number will be decoded.
                                                        ///< If count is greater than the number available in the raw data buffer,
                                                        ///< then the driver shall update the value with
                                                        ///< the actual number of decodable metric entries decoded. If set to null,
                                                        ///< then driver will only update the value of
                                                        ///< pSetCount.
        zet_metric_entry_exp_t* pMetricEntries          ///< [in,out][optional][range(0, *pMetricEntriesCount)] buffer containing
                                                        ///< decoded metric entries
        )
    {
        auto pfnDecodeExp = context.zetDdiTable.MetricTracerExp.pfnDecodeExp;

        if( nullptr == pfnDecodeExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerDecodeExpPrologue( phMetricDecoder, pRawDataSize, pRawData, metricsCount, phMetrics, pSetCount, pMetricEntriesCountPerSet, pMetricEntriesCount, pMetricEntries );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricTracerDecodeExpPrologue( phMetricDecoder, pRawDataSize, pRawData, metricsCount, phMetrics, pSetCount, pMetricEntriesCountPerSet, pMetricEntriesCount, pMetricEntries );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDecodeExp( phMetricDecoder, pRawDataSize, pRawData, metricsCount, phMetrics, pSetCount, pMetricEntriesCountPerSet, pMetricEntriesCount, pMetricEntries );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricTracerDecodeExpEpilogue( phMetricDecoder, pRawDataSize, pRawData, metricsCount, phMetrics, pSetCount, pMetricEntriesCountPerSet, pMetricEntriesCount, pMetricEntries ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupCalculateMultipleMetricValuesExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupCalculateMultipleMetricValuesExp(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        zet_metric_group_calculation_type_t type,       ///< [in] calculation type to be applied on raw data
        size_t rawDataSize,                             ///< [in] size in bytes of raw data buffer
        const uint8_t* pRawData,                        ///< [in][range(0, rawDataSize)] buffer of raw data to calculate
        uint32_t* pSetCount,                            ///< [in,out] pointer to number of metric sets.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metric sets to be calculated.
                                                        ///< if count is greater than the number available in the raw data buffer,
                                                        ///< then the driver shall update the value with the actual number of
                                                        ///< metric sets to be calculated.
        uint32_t* pTotalMetricValueCount,               ///< [in,out] pointer to number of the total number of metric values
                                                        ///< calculated, for all metric sets.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metric values to be calculated.
                                                        ///< if count is greater than the number available in the raw data buffer,
                                                        ///< then the driver shall update the value with the actual number of
                                                        ///< metric values to be calculated.
        uint32_t* pMetricCounts,                        ///< [in,out][optional][range(0, *pSetCount)] buffer of metric counts per
                                                        ///< metric set.
        zet_typed_value_t* pMetricValues                ///< [in,out][optional][range(0, *pTotalMetricValueCount)] buffer of
                                                        ///< calculated metrics.
                                                        ///< if count is less than the number available in the raw data buffer,
                                                        ///< then driver shall only calculate that number of metric values.
        )
    {
        auto pfnCalculateMultipleMetricValuesExp = context.zetDdiTable.MetricGroupExp.pfnCalculateMultipleMetricValuesExp;

        if( nullptr == pfnCalculateMultipleMetricValuesExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCalculateMultipleMetricValuesExpPrologue( hMetricGroup, type, rawDataSize, pRawData, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupCalculateMultipleMetricValuesExpPrologue( hMetricGroup, type, rawDataSize, pRawData, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCalculateMultipleMetricValuesExp( hMetricGroup, type, rawDataSize, pRawData, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCalculateMultipleMetricValuesExpEpilogue( hMetricGroup, type, rawDataSize, pRawData, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupGetGlobalTimestampsExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupGetGlobalTimestampsExp(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        ze_bool_t synchronizedWithHost,                 ///< [in] Returns the timestamps synchronized to the host or the device.
        uint64_t* globalTimestamp,                      ///< [out] Device timestamp.
        uint64_t* metricTimestamp                       ///< [out] Metric timestamp.
        )
    {
        auto pfnGetGlobalTimestampsExp = context.zetDdiTable.MetricGroupExp.pfnGetGlobalTimestampsExp;

        if( nullptr == pfnGetGlobalTimestampsExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetGlobalTimestampsExpPrologue( hMetricGroup, synchronizedWithHost, globalTimestamp, metricTimestamp );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupGetGlobalTimestampsExpPrologue( hMetricGroup, synchronizedWithHost, globalTimestamp, metricTimestamp );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetGlobalTimestampsExp( hMetricGroup, synchronizedWithHost, globalTimestamp, metricTimestamp );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetGlobalTimestampsExpEpilogue( hMetricGroup, synchronizedWithHost, globalTimestamp, metricTimestamp ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupGetExportDataExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupGetExportDataExp(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        const uint8_t* pRawData,                        ///< [in] buffer of raw data
        size_t rawDataSize,                             ///< [in] size in bytes of raw data buffer
        size_t* pExportDataSize,                        ///< [in,out] size in bytes of export data buffer
                                                        ///< if size is zero, then the driver shall update the value with the
                                                        ///< number of bytes necessary to store the exported data.
                                                        ///< if size is greater than required, then the driver shall update the
                                                        ///< value with the actual number of bytes necessary to store the exported data.
        uint8_t * pExportData                           ///< [in,out][optional][range(0, *pExportDataSize)] buffer of exported data.
        )
    {
        auto pfnGetExportDataExp = context.zetDdiTable.MetricGroupExp.pfnGetExportDataExp;

        if( nullptr == pfnGetExportDataExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetExportDataExpPrologue( hMetricGroup, pRawData, rawDataSize, pExportDataSize, pExportData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupGetExportDataExpPrologue( hMetricGroup, pRawData, rawDataSize, pExportDataSize, pExportData );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetExportDataExp( hMetricGroup, pRawData, rawDataSize, pExportDataSize, pExportData );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupGetExportDataExpEpilogue( hMetricGroup, pRawData, rawDataSize, pExportDataSize, pExportData ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupCalculateMetricExportDataExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupCalculateMetricExportDataExp(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        zet_metric_group_calculation_type_t type,       ///< [in] calculation type to be applied on raw data
        size_t exportDataSize,                          ///< [in] size in bytes of exported data buffer
        const uint8_t* pExportData,                     ///< [in][range(0, exportDataSize)] buffer of exported data to calculate
        zet_metric_calculate_exp_desc_t* pCalculateDescriptor,  ///< [in] descriptor specifying calculation specific parameters
        uint32_t* pSetCount,                            ///< [in,out] pointer to number of metric sets.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metric sets to be calculated.
                                                        ///< if count is greater than the number available in the raw data buffer,
                                                        ///< then the driver shall update the value with the actual number of
                                                        ///< metric sets to be calculated.
        uint32_t* pTotalMetricValueCount,               ///< [in,out] pointer to number of the total number of metric values
                                                        ///< calculated, for all metric sets.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metric values to be calculated.
                                                        ///< if count is greater than the number available in the raw data buffer,
                                                        ///< then the driver shall update the value with the actual number of
                                                        ///< metric values to be calculated.
        uint32_t* pMetricCounts,                        ///< [in,out][optional][range(0, *pSetCount)] buffer of metric counts per
                                                        ///< metric set.
        zet_typed_value_t* pMetricValues                ///< [in,out][optional][range(0, *pTotalMetricValueCount)] buffer of
                                                        ///< calculated metrics.
                                                        ///< if count is less than the number available in the raw data buffer,
                                                        ///< then driver shall only calculate that number of metric values.
        )
    {
        auto pfnCalculateMetricExportDataExp = context.zetDdiTable.MetricGroupExp.pfnCalculateMetricExportDataExp;

        if( nullptr == pfnCalculateMetricExportDataExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCalculateMetricExportDataExpPrologue( hDriver, type, exportDataSize, pExportData, pCalculateDescriptor, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupCalculateMetricExportDataExpPrologue( hDriver, type, exportDataSize, pExportData, pCalculateDescriptor, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCalculateMetricExportDataExp( hDriver, type, exportDataSize, pExportData, pCalculateDescriptor, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCalculateMetricExportDataExpEpilogue( hDriver, type, exportDataSize, pExportData, pCalculateDescriptor, pSetCount, pTotalMetricValueCount, pMetricCounts, pMetricValues ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricProgrammableGetExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricProgrammableGetExp(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of metric programmable handles.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of metric programmable handles available.
                                                        ///< if count is greater than the number of metric programmable handles
                                                        ///< available, then the driver shall update the value with the correct
                                                        ///< number of metric programmable handles available.
        zet_metric_programmable_exp_handle_t* phMetricProgrammables ///< [in,out][optional][range(0, *pCount)] array of handle of metric programmables.
                                                        ///< if count is less than the number of metric programmables available,
                                                        ///< then driver shall only retrieve that number of metric programmables.
        )
    {
        auto pfnGetExp = context.zetDdiTable.MetricProgrammableExp.pfnGetExp;

        if( nullptr == pfnGetExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetExpPrologue( hDevice, pCount, phMetricProgrammables );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricProgrammableGetExpPrologue( hDevice, pCount, phMetricProgrammables );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetExp( hDevice, pCount, phMetricProgrammables );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetExpEpilogue( hDevice, pCount, phMetricProgrammables ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            for (size_t i = 0; ( nullptr != phMetricProgrammables) && (i < *pCount); ++i){
                if (phMetricProgrammables[i]){
                    context.handleLifetime->addHandle( phMetricProgrammables[i] );
                    context.handleLifetime->addDependent( hDevice, phMetricProgrammables[i] );
                }
            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricProgrammableGetPropertiesExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricProgrammableGetPropertiesExp(
        zet_metric_programmable_exp_handle_t hMetricProgrammable,   ///< [in] handle of the metric programmable
        zet_metric_programmable_exp_properties_t* pProperties   ///< [in,out] properties of the metric programmable
        )
    {
        auto pfnGetPropertiesExp = context.zetDdiTable.MetricProgrammableExp.pfnGetPropertiesExp;

        if( nullptr == pfnGetPropertiesExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetPropertiesExpPrologue( hMetricProgrammable, pProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricProgrammableGetPropertiesExpPrologue( hMetricProgrammable, pProperties );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetPropertiesExp( hMetricProgrammable, pProperties );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetPropertiesExpEpilogue( hMetricProgrammable, pProperties ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricProgrammableGetParamInfoExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricProgrammableGetParamInfoExp(
        zet_metric_programmable_exp_handle_t hMetricProgrammable,   ///< [in] handle of the metric programmable
        uint32_t* pParameterCount,                      ///< [in,out] count of the parameters to retrieve parameter info.
                                                        ///< if value pParameterCount is greater than count of parameters
                                                        ///< available, then pParameterCount will be updated with count of
                                                        ///< parameters available.
                                                        ///< The count of parameters available can be queried using ::zetMetricProgrammableGetPropertiesExp.
        zet_metric_programmable_param_info_exp_t* pParameterInfo///< [in,out][range(1, *pParameterCount)] array of parameter info.
                                                        ///< if parameterCount is less than the number of parameters available,
                                                        ///< then driver shall only retrieve that number of parameter info.
        )
    {
        auto pfnGetParamInfoExp = context.zetDdiTable.MetricProgrammableExp.pfnGetParamInfoExp;

        if( nullptr == pfnGetParamInfoExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetParamInfoExpPrologue( hMetricProgrammable, pParameterCount, pParameterInfo );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricProgrammableGetParamInfoExpPrologue( hMetricProgrammable, pParameterCount, pParameterInfo );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetParamInfoExp( hMetricProgrammable, pParameterCount, pParameterInfo );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetParamInfoExpEpilogue( hMetricProgrammable, pParameterCount, pParameterInfo ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricProgrammableGetParamValueInfoExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricProgrammableGetParamValueInfoExp(
        zet_metric_programmable_exp_handle_t hMetricProgrammable,   ///< [in] handle of the metric programmable
        uint32_t parameterOrdinal,                      ///< [in] ordinal of the parameter in the metric programmable
        uint32_t* pValueInfoCount,                      ///< [in,out] count of parameter value information to retrieve.
                                                        ///< if value at pValueInfoCount is greater than count of value info
                                                        ///< available, then pValueInfoCount will be updated with count of value
                                                        ///< info available.
                                                        ///< The count of parameter value info available can be queried using ::zetMetricProgrammableGetParamInfoExp.
        zet_metric_programmable_param_value_info_exp_t* pValueInfo  ///< [in,out][range(1, *pValueInfoCount)] array of parameter value info.
                                                        ///< if pValueInfoCount is less than the number of value info available,
                                                        ///< then driver shall only retrieve that number of value info.
        )
    {
        auto pfnGetParamValueInfoExp = context.zetDdiTable.MetricProgrammableExp.pfnGetParamValueInfoExp;

        if( nullptr == pfnGetParamValueInfoExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetParamValueInfoExpPrologue( hMetricProgrammable, parameterOrdinal, pValueInfoCount, pValueInfo );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricProgrammableGetParamValueInfoExpPrologue( hMetricProgrammable, parameterOrdinal, pValueInfoCount, pValueInfo );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnGetParamValueInfoExp( hMetricProgrammable, parameterOrdinal, pValueInfoCount, pValueInfo );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricProgrammableGetParamValueInfoExpEpilogue( hMetricProgrammable, parameterOrdinal, pValueInfoCount, pValueInfo ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricCreateFromProgrammableExp2
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricCreateFromProgrammableExp2(
        zet_metric_programmable_exp_handle_t hMetricProgrammable,   ///< [in] handle of the metric programmable
        uint32_t parameterCount,                        ///< [in] Count of parameters to set.
        zet_metric_programmable_param_value_exp_t* pParameterValues,///< [in] list of parameter values to be set.
        const char* pName,                              ///< [in] pointer to metric name to be used. Must point to a
                                                        ///< null-terminated character array no longer than ::ZET_MAX_METRIC_NAME.
        const char* pDescription,                       ///< [in] pointer to metric description to be used. Must point to a
                                                        ///< null-terminated character array no longer than
                                                        ///< ::ZET_MAX_METRIC_DESCRIPTION.
        uint32_t* pMetricHandleCount,                   ///< [in,out] Pointer to the number of metric handles.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< number of metric handles available for this programmable.
                                                        ///< if count is greater than the number of metric handles available, then
                                                        ///< the driver shall update the value with the correct number of metric
                                                        ///< handles available.
        zet_metric_handle_t* phMetricHandles            ///< [in,out][optional][range(0,*pMetricHandleCount)] array of handle of metrics.
                                                        ///< if count is less than the number of metrics available, then driver
                                                        ///< shall only retrieve that number of metric handles.
        )
    {
        auto pfnCreateFromProgrammableExp2 = context.zetDdiTable.MetricExp.pfnCreateFromProgrammableExp2;

        if( nullptr == pfnCreateFromProgrammableExp2 )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricCreateFromProgrammableExp2Prologue( hMetricProgrammable, parameterCount, pParameterValues, pName, pDescription, pMetricHandleCount, phMetricHandles );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricCreateFromProgrammableExp2Prologue( hMetricProgrammable, parameterCount, pParameterValues, pName, pDescription, pMetricHandleCount, phMetricHandles );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreateFromProgrammableExp2( hMetricProgrammable, parameterCount, pParameterValues, pName, pDescription, pMetricHandleCount, phMetricHandles );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricCreateFromProgrammableExp2Epilogue( hMetricProgrammable, parameterCount, pParameterValues, pName, pDescription, pMetricHandleCount, phMetricHandles ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            for (size_t i = 0; ( nullptr != phMetricHandles) && (i < *pMetricHandleCount); ++i){
                if (phMetricHandles[i]){
                    context.handleLifetime->addHandle( phMetricHandles[i] );
                    context.handleLifetime->addDependent( hMetricProgrammable, phMetricHandles[i] );
                }
            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricCreateFromProgrammableExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricCreateFromProgrammableExp(
        zet_metric_programmable_exp_handle_t hMetricProgrammable,   ///< [in] handle of the metric programmable
        zet_metric_programmable_param_value_exp_t* pParameterValues,///< [in] list of parameter values to be set.
        uint32_t parameterCount,                        ///< [in] Count of parameters to set.
        const char* pName,                              ///< [in] pointer to metric name to be used. Must point to a
                                                        ///< null-terminated character array no longer than ::ZET_MAX_METRIC_NAME.
        const char* pDescription,                       ///< [in] pointer to metric description to be used. Must point to a
                                                        ///< null-terminated character array no longer than
                                                        ///< ::ZET_MAX_METRIC_DESCRIPTION.
        uint32_t* pMetricHandleCount,                   ///< [in,out] Pointer to the number of metric handles.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< number of metric handles available for this programmable.
                                                        ///< if count is greater than the number of metric handles available, then
                                                        ///< the driver shall update the value with the correct number of metric
                                                        ///< handles available.
        zet_metric_handle_t* phMetricHandles            ///< [in,out][optional][range(0,*pMetricHandleCount)] array of handle of metrics.
                                                        ///< if count is less than the number of metrics available, then driver
                                                        ///< shall only retrieve that number of metric handles.
        )
    {
        auto pfnCreateFromProgrammableExp = context.zetDdiTable.MetricExp.pfnCreateFromProgrammableExp;

        if( nullptr == pfnCreateFromProgrammableExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricCreateFromProgrammableExpPrologue( hMetricProgrammable, pParameterValues, parameterCount, pName, pDescription, pMetricHandleCount, phMetricHandles );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricCreateFromProgrammableExpPrologue( hMetricProgrammable, pParameterValues, parameterCount, pName, pDescription, pMetricHandleCount, phMetricHandles );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreateFromProgrammableExp( hMetricProgrammable, pParameterValues, parameterCount, pName, pDescription, pMetricHandleCount, phMetricHandles );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricCreateFromProgrammableExpEpilogue( hMetricProgrammable, pParameterValues, parameterCount, pName, pDescription, pMetricHandleCount, phMetricHandles ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            for (size_t i = 0; ( nullptr != phMetricHandles) && (i < *pMetricHandleCount); ++i){
                if (phMetricHandles[i]){
                    context.handleLifetime->addHandle( phMetricHandles[i] );
                    context.handleLifetime->addDependent( hMetricProgrammable, phMetricHandles[i] );
                }
            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDeviceCreateMetricGroupsFromMetricsExp
    __zedlllocal ze_result_t ZE_APICALL
    zetDeviceCreateMetricGroupsFromMetricsExp(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device.
        uint32_t metricCount,                           ///< [in] number of metric handles.
        zet_metric_handle_t * phMetrics,                ///< [in] metric handles to be added to the metric groups.
        const char * pMetricGroupNamePrefix,            ///< [in] prefix to the name created for the metric groups. Must point to a
                                                        ///< null-terminated character array no longer than
                                                        ///< ZEX_MAX_METRIC_GROUP_NAME_PREFIX.
        const char * pDescription,                      ///< [in] pointer to description of the metric groups. Must point to a
                                                        ///< null-terminated character array no longer than
                                                        ///< ::ZET_MAX_METRIC_GROUP_DESCRIPTION.
        uint32_t * pMetricGroupCount,                   ///< [in,out] pointer to the number of metric group handles to be created.
                                                        ///< if pMetricGroupCount is zero, then the driver shall update the value
                                                        ///< with the maximum possible number of metric group handles that could be created.
                                                        ///< if pMetricGroupCount is greater than the number of metric group
                                                        ///< handles that could be created, then the driver shall update the value
                                                        ///< with the correct number of metric group handles generated.
                                                        ///< if pMetricGroupCount is lesser than the number of metric group handles
                                                        ///< that could be created, then ::ZE_RESULT_ERROR_INVALID_ARGUMENT is returned.
        zet_metric_group_handle_t* phMetricGroup        ///< [in,out][optional][range(0, *pMetricGroupCount)] array of handle of
                                                        ///< metric group handles.
                                                        ///< Created Metric group handles.
        )
    {
        auto pfnCreateMetricGroupsFromMetricsExp = context.zetDdiTable.DeviceExp.pfnCreateMetricGroupsFromMetricsExp;

        if( nullptr == pfnCreateMetricGroupsFromMetricsExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDeviceCreateMetricGroupsFromMetricsExpPrologue( hDevice, metricCount, phMetrics, pMetricGroupNamePrefix, pDescription, pMetricGroupCount, phMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetDeviceCreateMetricGroupsFromMetricsExpPrologue( hDevice, metricCount, phMetrics, pMetricGroupNamePrefix, pDescription, pMetricGroupCount, phMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreateMetricGroupsFromMetricsExp( hDevice, metricCount, phMetrics, pMetricGroupNamePrefix, pDescription, pMetricGroupCount, phMetricGroup );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetDeviceCreateMetricGroupsFromMetricsExpEpilogue( hDevice, metricCount, phMetrics, pMetricGroupNamePrefix, pDescription, pMetricGroupCount, phMetricGroup ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            for (size_t i = 0; ( nullptr != phMetricGroup) && (i < *pMetricGroupCount); ++i){
                if (phMetricGroup[i]){
                    context.handleLifetime->addHandle( phMetricGroup[i] );
                    context.handleLifetime->addDependent( hDevice, phMetricGroup[i] );
                }
            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupCreateExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupCreateExp(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        const char* pName,                              ///< [in] pointer to metric group name. Must point to a null-terminated
                                                        ///< character array no longer than ::ZET_MAX_METRIC_GROUP_NAME.
        const char* pDescription,                       ///< [in] pointer to metric group description. Must point to a
                                                        ///< null-terminated character array no longer than
                                                        ///< ::ZET_MAX_METRIC_GROUP_DESCRIPTION.
        zet_metric_group_sampling_type_flags_t samplingType,///< [in] Sampling type for the metric group.
        zet_metric_group_handle_t* phMetricGroup        ///< [in,out] Created Metric group handle
        )
    {
        auto pfnCreateExp = context.zetDdiTable.MetricGroupExp.pfnCreateExp;

        if( nullptr == pfnCreateExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCreateExpPrologue( hDevice, pName, pDescription, samplingType, phMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupCreateExpPrologue( hDevice, pName, pDescription, samplingType, phMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCreateExp( hDevice, pName, pDescription, samplingType, phMetricGroup );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCreateExpEpilogue( hDevice, pName, pDescription, samplingType, phMetricGroup ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( driver_result == ZE_RESULT_SUCCESS && context.enableHandleLifetime ){
            
            if (phMetricGroup){
                context.handleLifetime->addHandle( *phMetricGroup );
                context.handleLifetime->addDependent( hDevice, *phMetricGroup );

            }
        }
        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupAddMetricExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupAddMetricExp(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] Handle of the metric group
        zet_metric_handle_t hMetric,                    ///< [in] Metric to be added to the group.
        size_t * pErrorStringSize,                      ///< [in,out][optional] Size of the error string to query, if an error was
                                                        ///< reported during adding the metric handle.
                                                        ///< if *pErrorStringSize is zero, then the driver shall update the value
                                                        ///< with the size of the error string in bytes.
        char* pErrorString                              ///< [in,out][optional][range(0, *pErrorStringSize)] Error string.
                                                        ///< if *pErrorStringSize is less than the length of the error string
                                                        ///< available, then driver shall only retrieve that length of error string.
        )
    {
        auto pfnAddMetricExp = context.zetDdiTable.MetricGroupExp.pfnAddMetricExp;

        if( nullptr == pfnAddMetricExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupAddMetricExpPrologue( hMetricGroup, hMetric, pErrorStringSize, pErrorString );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupAddMetricExpPrologue( hMetricGroup, hMetric, pErrorStringSize, pErrorString );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnAddMetricExp( hMetricGroup, hMetric, pErrorStringSize, pErrorString );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupAddMetricExpEpilogue( hMetricGroup, hMetric, pErrorStringSize, pErrorString ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupRemoveMetricExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupRemoveMetricExp(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] Handle of the metric group
        zet_metric_handle_t hMetric                     ///< [in] Metric handle to be removed from the metric group.
        )
    {
        auto pfnRemoveMetricExp = context.zetDdiTable.MetricGroupExp.pfnRemoveMetricExp;

        if( nullptr == pfnRemoveMetricExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupRemoveMetricExpPrologue( hMetricGroup, hMetric );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupRemoveMetricExpPrologue( hMetricGroup, hMetric );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnRemoveMetricExp( hMetricGroup, hMetric );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupRemoveMetricExpEpilogue( hMetricGroup, hMetric ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupCloseExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupCloseExp(
        zet_metric_group_handle_t hMetricGroup          ///< [in] Handle of the metric group
        )
    {
        auto pfnCloseExp = context.zetDdiTable.MetricGroupExp.pfnCloseExp;

        if( nullptr == pfnCloseExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCloseExpPrologue( hMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupCloseExpPrologue( hMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnCloseExp( hMetricGroup );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupCloseExpEpilogue( hMetricGroup ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupDestroyExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricGroupDestroyExp(
        zet_metric_group_handle_t hMetricGroup          ///< [in] Handle of the metric group to destroy
        )
    {
        auto pfnDestroyExp = context.zetDdiTable.MetricGroupExp.pfnDestroyExp;

        if( nullptr == pfnDestroyExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupDestroyExpPrologue( hMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricGroupDestroyExpPrologue( hMetricGroup );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDestroyExp( hMetricGroup );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricGroupDestroyExpEpilogue( hMetricGroup ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricDestroyExp
    __zedlllocal ze_result_t ZE_APICALL
    zetMetricDestroyExp(
        zet_metric_handle_t hMetric                     ///< [in] Handle of the metric to destroy
        )
    {
        auto pfnDestroyExp = context.zetDdiTable.MetricExp.pfnDestroyExp;

        if( nullptr == pfnDestroyExp )
            return ZE_RESULT_ERROR_UNSUPPORTED_FEATURE;

        auto numValHandlers = context.validationHandlers.size();
        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDestroyExpPrologue( hMetric );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }


        if( context.enableThreadingValidation ){ 
            //Unimplemented
        }

        
        if(context.enableHandleLifetime ){
            auto result = context.handleLifetime->zetHandleLifetime.zetMetricDestroyExpPrologue( hMetric );
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        auto driver_result = pfnDestroyExp( hMetric );

        for (size_t i = 0; i < numValHandlers; i++) {
            auto result = context.validationHandlers[i]->zetValidation->zetMetricDestroyExpEpilogue( hMetric ,driver_result);
            if(result!=ZE_RESULT_SUCCESS) return result;
        }

        return driver_result;
    }

} // namespace validation_layer

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricDecoderExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricDecoderExpProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_decoder_exp_dditable_t* pDdiTable    ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricDecoderExp;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreateExp                                = pDdiTable->pfnCreateExp;
    pDdiTable->pfnCreateExp                              = validation_layer::zetMetricDecoderCreateExp;

    dditable.pfnDestroyExp                               = pDdiTable->pfnDestroyExp;
    pDdiTable->pfnDestroyExp                             = validation_layer::zetMetricDecoderDestroyExp;

    dditable.pfnGetDecodableMetricsExp                   = pDdiTable->pfnGetDecodableMetricsExp;
    pDdiTable->pfnGetDecodableMetricsExp                 = validation_layer::zetMetricDecoderGetDecodableMetricsExp;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricProgrammableExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricProgrammableExpProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_programmable_exp_dditable_t* pDdiTable   ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricProgrammableExp;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGetExp                                   = pDdiTable->pfnGetExp;
    pDdiTable->pfnGetExp                                 = validation_layer::zetMetricProgrammableGetExp;

    dditable.pfnGetPropertiesExp                         = pDdiTable->pfnGetPropertiesExp;
    pDdiTable->pfnGetPropertiesExp                       = validation_layer::zetMetricProgrammableGetPropertiesExp;

    dditable.pfnGetParamInfoExp                          = pDdiTable->pfnGetParamInfoExp;
    pDdiTable->pfnGetParamInfoExp                        = validation_layer::zetMetricProgrammableGetParamInfoExp;

    dditable.pfnGetParamValueInfoExp                     = pDdiTable->pfnGetParamValueInfoExp;
    pDdiTable->pfnGetParamValueInfoExp                   = validation_layer::zetMetricProgrammableGetParamValueInfoExp;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricTracerExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricTracerExpProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_tracer_exp_dditable_t* pDdiTable     ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricTracerExp;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreateExp                                = pDdiTable->pfnCreateExp;
    pDdiTable->pfnCreateExp                              = validation_layer::zetMetricTracerCreateExp;

    dditable.pfnDestroyExp                               = pDdiTable->pfnDestroyExp;
    pDdiTable->pfnDestroyExp                             = validation_layer::zetMetricTracerDestroyExp;

    dditable.pfnEnableExp                                = pDdiTable->pfnEnableExp;
    pDdiTable->pfnEnableExp                              = validation_layer::zetMetricTracerEnableExp;

    dditable.pfnDisableExp                               = pDdiTable->pfnDisableExp;
    pDdiTable->pfnDisableExp                             = validation_layer::zetMetricTracerDisableExp;

    dditable.pfnReadDataExp                              = pDdiTable->pfnReadDataExp;
    pDdiTable->pfnReadDataExp                            = validation_layer::zetMetricTracerReadDataExp;

    dditable.pfnDecodeExp                                = pDdiTable->pfnDecodeExp;
    pDdiTable->pfnDecodeExp                              = validation_layer::zetMetricTracerDecodeExp;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetDeviceProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_device_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.Device;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGetDebugProperties                       = pDdiTable->pfnGetDebugProperties;
    pDdiTable->pfnGetDebugProperties                     = validation_layer::zetDeviceGetDebugProperties;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's DeviceExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetDeviceExpProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_device_exp_dditable_t* pDdiTable            ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.DeviceExp;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGetConcurrentMetricGroupsExp             = pDdiTable->pfnGetConcurrentMetricGroupsExp;
    pDdiTable->pfnGetConcurrentMetricGroupsExp           = validation_layer::zetDeviceGetConcurrentMetricGroupsExp;

    dditable.pfnCreateMetricGroupsFromMetricsExp         = pDdiTable->pfnCreateMetricGroupsFromMetricsExp;
    pDdiTable->pfnCreateMetricGroupsFromMetricsExp       = validation_layer::zetDeviceCreateMetricGroupsFromMetricsExp;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Context table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetContextProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_context_dditable_t* pDdiTable               ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.Context;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnActivateMetricGroups                     = pDdiTable->pfnActivateMetricGroups;
    pDdiTable->pfnActivateMetricGroups                   = validation_layer::zetContextActivateMetricGroups;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetCommandListProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_command_list_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.CommandList;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnAppendMetricStreamerMarker               = pDdiTable->pfnAppendMetricStreamerMarker;
    pDdiTable->pfnAppendMetricStreamerMarker             = validation_layer::zetCommandListAppendMetricStreamerMarker;

    dditable.pfnAppendMetricQueryBegin                   = pDdiTable->pfnAppendMetricQueryBegin;
    pDdiTable->pfnAppendMetricQueryBegin                 = validation_layer::zetCommandListAppendMetricQueryBegin;

    dditable.pfnAppendMetricQueryEnd                     = pDdiTable->pfnAppendMetricQueryEnd;
    pDdiTable->pfnAppendMetricQueryEnd                   = validation_layer::zetCommandListAppendMetricQueryEnd;

    dditable.pfnAppendMetricMemoryBarrier                = pDdiTable->pfnAppendMetricMemoryBarrier;
    pDdiTable->pfnAppendMetricMemoryBarrier              = validation_layer::zetCommandListAppendMetricMemoryBarrier;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Kernel table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetKernelProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_kernel_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.Kernel;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGetProfileInfo                           = pDdiTable->pfnGetProfileInfo;
    pDdiTable->pfnGetProfileInfo                         = validation_layer::zetKernelGetProfileInfo;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Module table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetModuleProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_module_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.Module;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGetDebugInfo                             = pDdiTable->pfnGetDebugInfo;
    pDdiTable->pfnGetDebugInfo                           = validation_layer::zetModuleGetDebugInfo;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Debug table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetDebugProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_debug_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.Debug;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnAttach                                   = pDdiTable->pfnAttach;
    pDdiTable->pfnAttach                                 = validation_layer::zetDebugAttach;

    dditable.pfnDetach                                   = pDdiTable->pfnDetach;
    pDdiTable->pfnDetach                                 = validation_layer::zetDebugDetach;

    dditable.pfnReadEvent                                = pDdiTable->pfnReadEvent;
    pDdiTable->pfnReadEvent                              = validation_layer::zetDebugReadEvent;

    dditable.pfnAcknowledgeEvent                         = pDdiTable->pfnAcknowledgeEvent;
    pDdiTable->pfnAcknowledgeEvent                       = validation_layer::zetDebugAcknowledgeEvent;

    dditable.pfnInterrupt                                = pDdiTable->pfnInterrupt;
    pDdiTable->pfnInterrupt                              = validation_layer::zetDebugInterrupt;

    dditable.pfnResume                                   = pDdiTable->pfnResume;
    pDdiTable->pfnResume                                 = validation_layer::zetDebugResume;

    dditable.pfnReadMemory                               = pDdiTable->pfnReadMemory;
    pDdiTable->pfnReadMemory                             = validation_layer::zetDebugReadMemory;

    dditable.pfnWriteMemory                              = pDdiTable->pfnWriteMemory;
    pDdiTable->pfnWriteMemory                            = validation_layer::zetDebugWriteMemory;

    dditable.pfnGetRegisterSetProperties                 = pDdiTable->pfnGetRegisterSetProperties;
    pDdiTable->pfnGetRegisterSetProperties               = validation_layer::zetDebugGetRegisterSetProperties;

    dditable.pfnReadRegisters                            = pDdiTable->pfnReadRegisters;
    pDdiTable->pfnReadRegisters                          = validation_layer::zetDebugReadRegisters;

    dditable.pfnWriteRegisters                           = pDdiTable->pfnWriteRegisters;
    pDdiTable->pfnWriteRegisters                         = validation_layer::zetDebugWriteRegisters;

    dditable.pfnGetThreadRegisterSetProperties           = pDdiTable->pfnGetThreadRegisterSetProperties;
    pDdiTable->pfnGetThreadRegisterSetProperties         = validation_layer::zetDebugGetThreadRegisterSetProperties;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Metric table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.Metric;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGet                                      = pDdiTable->pfnGet;
    pDdiTable->pfnGet                                    = validation_layer::zetMetricGet;

    dditable.pfnGetProperties                            = pDdiTable->pfnGetProperties;
    pDdiTable->pfnGetProperties                          = validation_layer::zetMetricGetProperties;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricExpProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_exp_dditable_t* pDdiTable            ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricExp;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreateFromProgrammableExp2               = pDdiTable->pfnCreateFromProgrammableExp2;
    pDdiTable->pfnCreateFromProgrammableExp2             = validation_layer::zetMetricCreateFromProgrammableExp2;

    dditable.pfnCreateFromProgrammableExp                = pDdiTable->pfnCreateFromProgrammableExp;
    pDdiTable->pfnCreateFromProgrammableExp              = validation_layer::zetMetricCreateFromProgrammableExp;

    dditable.pfnDestroyExp                               = pDdiTable->pfnDestroyExp;
    pDdiTable->pfnDestroyExp                             = validation_layer::zetMetricDestroyExp;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricGroup table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricGroupProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_group_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricGroup;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGet                                      = pDdiTable->pfnGet;
    pDdiTable->pfnGet                                    = validation_layer::zetMetricGroupGet;

    dditable.pfnGetProperties                            = pDdiTable->pfnGetProperties;
    pDdiTable->pfnGetProperties                          = validation_layer::zetMetricGroupGetProperties;

    dditable.pfnCalculateMetricValues                    = pDdiTable->pfnCalculateMetricValues;
    pDdiTable->pfnCalculateMetricValues                  = validation_layer::zetMetricGroupCalculateMetricValues;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricGroupExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricGroupExpProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_group_exp_dditable_t* pDdiTable      ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricGroupExp;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCalculateMultipleMetricValuesExp         = pDdiTable->pfnCalculateMultipleMetricValuesExp;
    pDdiTable->pfnCalculateMultipleMetricValuesExp       = validation_layer::zetMetricGroupCalculateMultipleMetricValuesExp;

    dditable.pfnGetGlobalTimestampsExp                   = pDdiTable->pfnGetGlobalTimestampsExp;
    pDdiTable->pfnGetGlobalTimestampsExp                 = validation_layer::zetMetricGroupGetGlobalTimestampsExp;

    dditable.pfnGetExportDataExp                         = pDdiTable->pfnGetExportDataExp;
    pDdiTable->pfnGetExportDataExp                       = validation_layer::zetMetricGroupGetExportDataExp;

    dditable.pfnCalculateMetricExportDataExp             = pDdiTable->pfnCalculateMetricExportDataExp;
    pDdiTable->pfnCalculateMetricExportDataExp           = validation_layer::zetMetricGroupCalculateMetricExportDataExp;

    dditable.pfnCreateExp                                = pDdiTable->pfnCreateExp;
    pDdiTable->pfnCreateExp                              = validation_layer::zetMetricGroupCreateExp;

    dditable.pfnAddMetricExp                             = pDdiTable->pfnAddMetricExp;
    pDdiTable->pfnAddMetricExp                           = validation_layer::zetMetricGroupAddMetricExp;

    dditable.pfnRemoveMetricExp                          = pDdiTable->pfnRemoveMetricExp;
    pDdiTable->pfnRemoveMetricExp                        = validation_layer::zetMetricGroupRemoveMetricExp;

    dditable.pfnCloseExp                                 = pDdiTable->pfnCloseExp;
    pDdiTable->pfnCloseExp                               = validation_layer::zetMetricGroupCloseExp;

    dditable.pfnDestroyExp                               = pDdiTable->pfnDestroyExp;
    pDdiTable->pfnDestroyExp                             = validation_layer::zetMetricGroupDestroyExp;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQuery table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricQueryProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_query_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricQuery;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = validation_layer::zetMetricQueryCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = validation_layer::zetMetricQueryDestroy;

    dditable.pfnReset                                    = pDdiTable->pfnReset;
    pDdiTable->pfnReset                                  = validation_layer::zetMetricQueryReset;

    dditable.pfnGetData                                  = pDdiTable->pfnGetData;
    pDdiTable->pfnGetData                                = validation_layer::zetMetricQueryGetData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQueryPool table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricQueryPoolProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_query_pool_dditable_t* pDdiTable     ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricQueryPool;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = validation_layer::zetMetricQueryPoolCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = validation_layer::zetMetricQueryPoolDestroy;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricStreamer table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricStreamerProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_streamer_dditable_t* pDdiTable       ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.MetricStreamer;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnOpen                                     = pDdiTable->pfnOpen;
    pDdiTable->pfnOpen                                   = validation_layer::zetMetricStreamerOpen;

    dditable.pfnClose                                    = pDdiTable->pfnClose;
    pDdiTable->pfnClose                                  = validation_layer::zetMetricStreamerClose;

    dditable.pfnReadData                                 = pDdiTable->pfnReadData;
    pDdiTable->pfnReadData                               = validation_layer::zetMetricStreamerReadData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's TracerExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetTracerExpProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_tracer_exp_dditable_t* pDdiTable            ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = validation_layer::context.zetDdiTable.TracerExp;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if (ZE_MAJOR_VERSION(validation_layer::context.version) != ZE_MAJOR_VERSION(version) ||
        ZE_MINOR_VERSION(validation_layer::context.version) > ZE_MINOR_VERSION(version))
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = validation_layer::zetTracerExpCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = validation_layer::zetTracerExpDestroy;

    dditable.pfnSetPrologues                             = pDdiTable->pfnSetPrologues;
    pDdiTable->pfnSetPrologues                           = validation_layer::zetTracerExpSetPrologues;

    dditable.pfnSetEpilogues                             = pDdiTable->pfnSetEpilogues;
    pDdiTable->pfnSetEpilogues                           = validation_layer::zetTracerExpSetEpilogues;

    dditable.pfnSetEnabled                               = pDdiTable->pfnSetEnabled;
    pDdiTable->pfnSetEnabled                             = validation_layer::zetTracerExpSetEnabled;

    return result;
}

#if defined(__cplusplus)
};
#endif
