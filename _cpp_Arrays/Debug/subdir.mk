################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../2sum.cpp \
../3sum.cpp \
../_main.cpp \
../asteroid_collision.cpp \
../buy_sell_stock.cpp \
../buy_sell_stock_III.cpp \
../count_pairs_with_diff_k.cpp \
../duplicate_zeros.cpp \
../find_duplicate_E_M.cpp \
../find_peak.cpp \
../find_pivot.cpp \
../first_last_occurence.cpp \
../fruits_in_basket.cpp \
../intersection_of_2_arrays_I.cpp \
../intersection_of_2_arrays_II.cpp \
../interval_list_intersection.cpp \
../intervals_merge.cpp \
../k_closest_elements.cpp \
../k_closest_points_to_origin.cpp \
../k_frequent_numbers.cpp \
../k_frequent_words.cpp \
../k_smallest_numbers.cpp \
../kth_largest_element.cpp \
../majority_element.cpp \
../max_consecutive_ones_I.cpp \
../max_consecutive_ones_II.cpp \
../max_consecutive_ones_III.cpp \
../meeting_rooms.cpp \
../merge_2_sorted_arrays.cpp \
../merge_k_sorted_arrays.cpp \
../min_cost_connect_ropes.cpp \
../min_in_sorted_rotated_array.cpp \
../min_max.cpp \
../most_water_in_container.cpp \
../move_zeroes.cpp \
../optimal_utilization.cpp \
../pair_sum_close_to_0.cpp \
../peaks_and_valleys.cpp \
../product_of_array_except_self.cpp \
../rearrange_pos_neg.cpp \
../remove_duplicates.cpp \
../search_in_rotated_sorted_array.cpp \
../single_number.cpp \
../sort_colors_dutch_flag.cpp \
../squaring\ _sorted_array.cpp \
../subarray_max_product.cpp \
../subarray_max_size_k.cpp \
../subarray_max_sum.cpp \
../subarray_max_sum_k.cpp \
../subarray_sum_0_largest.cpp \
../subarray_with_sum_0.cpp \
../subarray_with_sum_k.cpp \
../two_array_sum_swap.cpp \
../water_jug.cpp 

OBJS += \
./2sum.o \
./3sum.o \
./_main.o \
./asteroid_collision.o \
./buy_sell_stock.o \
./buy_sell_stock_III.o \
./count_pairs_with_diff_k.o \
./duplicate_zeros.o \
./find_duplicate_E_M.o \
./find_peak.o \
./find_pivot.o \
./first_last_occurence.o \
./fruits_in_basket.o \
./intersection_of_2_arrays_I.o \
./intersection_of_2_arrays_II.o \
./interval_list_intersection.o \
./intervals_merge.o \
./k_closest_elements.o \
./k_closest_points_to_origin.o \
./k_frequent_numbers.o \
./k_frequent_words.o \
./k_smallest_numbers.o \
./kth_largest_element.o \
./majority_element.o \
./max_consecutive_ones_I.o \
./max_consecutive_ones_II.o \
./max_consecutive_ones_III.o \
./meeting_rooms.o \
./merge_2_sorted_arrays.o \
./merge_k_sorted_arrays.o \
./min_cost_connect_ropes.o \
./min_in_sorted_rotated_array.o \
./min_max.o \
./most_water_in_container.o \
./move_zeroes.o \
./optimal_utilization.o \
./pair_sum_close_to_0.o \
./peaks_and_valleys.o \
./product_of_array_except_self.o \
./rearrange_pos_neg.o \
./remove_duplicates.o \
./search_in_rotated_sorted_array.o \
./single_number.o \
./sort_colors_dutch_flag.o \
./squaring\ _sorted_array.o \
./subarray_max_product.o \
./subarray_max_size_k.o \
./subarray_max_sum.o \
./subarray_max_sum_k.o \
./subarray_sum_0_largest.o \
./subarray_with_sum_0.o \
./subarray_with_sum_k.o \
./two_array_sum_swap.o \
./water_jug.o 

CPP_DEPS += \
./2sum.d \
./3sum.d \
./_main.d \
./asteroid_collision.d \
./buy_sell_stock.d \
./buy_sell_stock_III.d \
./count_pairs_with_diff_k.d \
./duplicate_zeros.d \
./find_duplicate_E_M.d \
./find_peak.d \
./find_pivot.d \
./first_last_occurence.d \
./fruits_in_basket.d \
./intersection_of_2_arrays_I.d \
./intersection_of_2_arrays_II.d \
./interval_list_intersection.d \
./intervals_merge.d \
./k_closest_elements.d \
./k_closest_points_to_origin.d \
./k_frequent_numbers.d \
./k_frequent_words.d \
./k_smallest_numbers.d \
./kth_largest_element.d \
./majority_element.d \
./max_consecutive_ones_I.d \
./max_consecutive_ones_II.d \
./max_consecutive_ones_III.d \
./meeting_rooms.d \
./merge_2_sorted_arrays.d \
./merge_k_sorted_arrays.d \
./min_cost_connect_ropes.d \
./min_in_sorted_rotated_array.d \
./min_max.d \
./most_water_in_container.d \
./move_zeroes.d \
./optimal_utilization.d \
./pair_sum_close_to_0.d \
./peaks_and_valleys.d \
./product_of_array_except_self.d \
./rearrange_pos_neg.d \
./remove_duplicates.d \
./search_in_rotated_sorted_array.d \
./single_number.d \
./sort_colors_dutch_flag.d \
./squaring\ _sorted_array.d \
./subarray_max_product.d \
./subarray_max_size_k.d \
./subarray_max_sum.d \
./subarray_max_sum_k.d \
./subarray_sum_0_largest.d \
./subarray_with_sum_0.d \
./subarray_with_sum_k.d \
./two_array_sum_swap.d \
./water_jug.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

squaring\ _sorted_array.o: ../squaring\ _sorted_array.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"squaring _sorted_array.d" -MT"squaring\ _sorted_array.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


